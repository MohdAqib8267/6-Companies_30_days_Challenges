# Write your MySQL query statement below
delete b from Person a
join Person b
where a.id < b.id and a.email = b.email;
