# Write your MySQL query statement below

# First get all the salespersons id who had orders related to compant RED
WITH cte AS 
(SELECT o.sales_id
FROM Orders o
LEFT JOIN Company c
ON o.com_id = c.com_id
WHERE c.name = "RED")

# Then get a table where all data have salespersons id NOT IN first table.
# At last just get the names from that second table
SELECT name
FROM SalesPerson 
WHERE sales_id NOT IN (SELECT DISTINCT sales_id FROM cte)
