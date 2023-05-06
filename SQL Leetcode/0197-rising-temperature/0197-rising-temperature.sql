# Write your MySQL query statement below

SELECT x.id
FROM Weather x, Weather y
WHERE (x.temperature > y.temperature AND DATEDIFF(x.recordDate,y.recordDate)=1)