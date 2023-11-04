# Write your MySQL query statement below
select name from SalesPerson
where sales_id not in
(select o.sales_id from Orders as o
left join Company as c
 on c.com_id = o.com_id
 where c.name='red'
)