# Write your MySQL query statement below
SELECT employer.name as Employee
FROM Employee 
employer JOIN Employee manager ON (employer.managerId = manager.id)
WHERE employer.salary>manager.salary