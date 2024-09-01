# Write your MySQL query statement below
# with cte as(
#     select email,count(email) as cnt from Person
#     group by email
# )
# select email as Email from cte 
# where cnt>1

select Email from Person
group by Email
having count(Email)>1