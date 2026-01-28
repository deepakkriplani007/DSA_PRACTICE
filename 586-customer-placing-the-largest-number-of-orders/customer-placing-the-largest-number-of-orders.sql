WITH cts AS (
    SELECT customer_number, COUNT(*) AS cnt
    FROM orders
    GROUP BY customer_number
)
SELECT customer_number
FROM cts
WHERE cnt = (SELECT MAX(cnt) FROM cts);
