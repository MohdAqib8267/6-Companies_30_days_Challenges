# Write your MySQL query statement below
select dep.name as Department, emp.name as Employee, emp.salary as Salary
from Employee as emp
inner join Department as dep
on emp.departmentId = dep.id
where(emp.salary,emp.departmentId) in
(select max(salary),departmentId from Employee group by departmentId);