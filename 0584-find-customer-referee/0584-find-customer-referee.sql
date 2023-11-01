# Write your MySQL query statement below
select Cust.name as name from Customer as Cust
where (Cust.referee_id is null || Cust.referee_id != 2)