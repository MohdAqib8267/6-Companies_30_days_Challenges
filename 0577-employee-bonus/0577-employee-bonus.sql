# Write your MySQL query statement below
SELECT name,bonus from Employee as T1
left join Bonus as T2
on T1.empId=T2.empId
where T2.bonus<1000 or T2.bonus is null;
