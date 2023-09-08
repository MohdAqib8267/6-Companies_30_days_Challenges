# Write your MySQL query statement below
select * from Cinema
where Cinema.description != "boring" and Cinema.id%2!=0
order by Cinema.rating DESC;