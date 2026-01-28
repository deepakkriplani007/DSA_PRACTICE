/* Write your T-SQL query statement below */
SELECT 
    COALESCE(s.employee_id, e.employee_id ) employee_id 
FROM Employees e
FULL OUTER JOIN Salaries s on e.employee_id = s.employee_id
WHERE e.employee_id IS NULL OR s.employee_id IS NULL
ORDER BY employee_id