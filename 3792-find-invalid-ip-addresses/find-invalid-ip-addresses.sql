WITH distinct_ips AS (
    SELECT DISTINCT ip
    FROM logs
),
split_ip AS (
    SELECT
        d.ip,
        value AS octet,
        COUNT(*) OVER (PARTITION BY d.ip) AS octet_count
    FROM distinct_ips d
    CROSS APPLY STRING_SPLIT(d.ip, '.')
),
invalid_ips AS (
    SELECT DISTINCT ip
    FROM split_ip
    WHERE
        octet_count <> 4
        OR TRY_CAST(octet AS INT) > 255
        OR (LEN(octet) > 1 AND octet LIKE '0%')
)
SELECT
    l.ip,
    COUNT(*) AS invalid_count
FROM logs l
JOIN invalid_ips i
    ON l.ip = i.ip
GROUP BY l.ip
ORDER BY invalid_count DESC, l.ip DESC;
