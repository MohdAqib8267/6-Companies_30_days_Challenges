# Write your MySQL query statement below
WITH CTE AS (
    SELECT
        num,
       LAG(num, 1) OVER (ORDER BY id) AS PREV,
        LEAD(num, 1) OVER (ORDER BY id) AS NEXT
    FROM Logs
)
select distinct num as ConsecutiveNums from CTE
where PREV=num and NEXT=num; 