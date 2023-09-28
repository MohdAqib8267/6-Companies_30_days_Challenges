# Write your MySQL query statement below
select cust.name as name from Customer as cust
where (cust.referee_id is null || cust.referee_id!=2);