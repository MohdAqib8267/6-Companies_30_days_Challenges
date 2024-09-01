# Write your MySQL query statement below
with cte as(
    select d.name as Department,e.name as name,e.salary as Salary,
    DENSE_RANK() over(partition by e.departmentId order by e.salary DESC) as "rank"
    from Employee as e
    inner join Department as d
    on d.id = e.departmentId
    
)
# select * from cte
select cte.Department,cte.name as Employee, cte.Salary
from cte
where cte.rank<=3