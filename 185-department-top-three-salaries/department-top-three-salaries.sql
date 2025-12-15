-- SELECT department, employee, salary
-- FROM (
--     SELECT 
--         d.name AS department,
--         e.name AS employee,
--         e.salary,
--         DENSE_RANK() OVER (
--             PARTITION BY d.name
--             ORDER BY e.salary DESC
--         ) AS salary_rank
--     FROM Department d
--     JOIN Employee e
--         ON d.id = e.id
-- ) t
-- WHERE salary_rank <= 3;

select Department,Employee,Salary from (
    select a.name as Department ,b.name as Employee  ,b.salary as Salary ,dense_rank() over(partition by a.name order by b.salary desc) 
    as ran from department a join employee b on( a.id=b.departmentId)
    ) t where ran<=3