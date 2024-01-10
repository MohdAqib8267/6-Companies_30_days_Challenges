# Write your MySQL query statement below
with cte as(
select r.contest_id, count(r.user_id) as count
    from Users as u
    right join Register as r
    on r.user_id =u.user_id
    GROUP By r.contest_id
)
select contest_id, round((count/(select count(user_id) from users)*100),2) as percentage from cte
ORDER By percentage DESC,contest_id;