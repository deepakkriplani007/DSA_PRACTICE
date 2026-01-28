/* Write your T-SQL query statement below */
select employee_id from
(select case when e.name is null or  s.salary is null then
(case when s.employee_id is null then e.employee_id when e.employee_id is null then s.employee_id end) 
end as employee_id
from employees e full outer join salaries s on e.employee_id=s.employee_id)
a where employee_id is not null order by employee_id