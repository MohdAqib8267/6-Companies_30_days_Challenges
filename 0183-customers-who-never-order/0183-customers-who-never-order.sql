SELECT cust.name as Customers
FROM Customers AS cust
WHERE cust.id NOT IN (SELECT customerId FROM Orders);
