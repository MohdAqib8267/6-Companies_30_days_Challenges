# Write your MySQL query statement below
with my_table as(
    SELECT 
        customer_id,
            COUNT(DISTINCT product_key) AS product_count
        FROM 
            Customer
        GROUP BY 
            customer_id
)
select customer_id
from my_table
where product_count = (select count(*) from Product)