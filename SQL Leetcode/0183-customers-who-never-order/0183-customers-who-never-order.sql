# Write your MySQL query statement below
# hamesha FROM se likhna start karo
# refer this if needed => https://www.youtube.com/watch?v=ddeiGdMWtbQ&list=PLtfxzVLWb-B_V2BPwlXOmrbO4a-a43Eg5&index=4

SELECT c.name AS Customers
FROM Customers c
LEFT JOIN Orders o
ON c.id = o.customerid
WHERE o.customerid IS NULL