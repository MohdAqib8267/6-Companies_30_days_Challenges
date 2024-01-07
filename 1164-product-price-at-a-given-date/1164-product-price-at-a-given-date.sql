# Write your MySQL query statement below

with cte as (
    select product_id, change_date
    from products
    where (change_date <= date('2019-08-16'))
)

select product_id, new_price as price
from products
where (product_id, change_date) IN (
    select product_id,max(change_date)
    from cte
    group by product_id
)
union
select product_id, 10
from products
where not product_id IN (select product_id from cte);