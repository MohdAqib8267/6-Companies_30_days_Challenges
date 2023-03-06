# Write your MySQL query statement below

# select email from person
# group by email 
# having count(email)>1

SELECT DISTINCT(p1.email) from 
Person p1 JOIN Person p2 ON
p1.email = p2.email AND p1.id != p2.id;

