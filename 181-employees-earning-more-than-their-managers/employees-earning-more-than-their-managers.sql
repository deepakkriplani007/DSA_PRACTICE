/* Write your T-SQL query statement below */
select  a.name as Employee from Employee  a 
where a.managerId is not null and a.salary>(
    select b.salary from Employee b where a.managerId=b.id
    )