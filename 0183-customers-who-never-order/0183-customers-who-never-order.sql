# Write your MySQL query statement below
select c1.name as Customers from Customers as c1
left join Orders as o
on c1.id = o.customerId
where o.customerId is null