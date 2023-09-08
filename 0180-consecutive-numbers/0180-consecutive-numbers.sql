# Write your MySQL query statement below
WITH CTE As(
    select num,
    LAG(num,1) OVER(order by id) As PREV,
    LEAD(num,1) OVER(order by id) As NEXT
    from Logs
)
select distinct num as ConsecutiveNums from CTE
where PREV=num and NEXT=num; 