SELECT 
    request_at AS Day, 
    ROUND(SUM(IF(Status <> 'completed', 1, 0)) / COUNT(Status), 2) AS "Cancellation Rate"
FROM 
    Trips
WHERE
    request_at BETWEEN "2013-10-01" AND "2013-10-03"
    AND client_id NOT IN (SELECT users_id from Users WHERE banned="YES")
    AND driver_id NOT IN (SELECT users_id from Users WHERE banned="YES")
GROUP BY 
    request_at;



