# Write your MySQL query statement below

select distinct a.num as ConsecutiveNums from Logs as a
join Logs as b
on a.id=b.id+1 and a.num=b.num
join Logs as c
on a.id=c.id+2 and a.num=c.num;