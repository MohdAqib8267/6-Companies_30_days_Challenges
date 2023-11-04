# Write your MySQL query statement below
select d.name as Department, e.name as Employee, e.salary as Salary
from Employee as e
inner join Department as d
on e.departmentId = d.id
where (e.salary, e.departmentId) in
(select max(salary), departmentId from Employee group by departmentId);