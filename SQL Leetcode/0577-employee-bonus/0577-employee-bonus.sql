# Write your MySQL query statement below

# ques mein null bhi tha output mein isiliye IS NULL laga diya varna bonus<1000 se hi hona chahiye tha
# Acc to ques, join ke baad emp ka name rahega which lies in the 1st table so will use LEFT JOIN
SELECT e.name,b.bonus
FROM Employee e LEFT JOIN Bonus b
ON e.empId = b.empId
WHERE b.bonus IS NULL or b.bonus < 1000 