CREATE FUNCTION getNthHighestSalary(N INT) RETURNS INT
BEGIN
SET N = N - 1;
  RETURN (
      # Write your MySQL query statement below.
      select DISTINCT e.salary as getNthHighestSalary from Employee as e
      order by e.salary desc
      limit 1 offset N
  );
END