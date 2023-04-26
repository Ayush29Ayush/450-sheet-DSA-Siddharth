# Write your MySQL query statement below
# Table ke contents khud hi se compare karvane hai => So think of JOIN
# Always start by writing the FROM first
# Agar khudse join karva rahe ho them ALIAS is a must
# Here id is the primary key and the managerId is the foriegn key
# from the example we can observe ki left ka sara data hai and right table ka agar data nahi hai then its NULL
# This means left join use karna hoga

SELECT e1.name AS Employee
FROM Employee e1 
LEFT JOIN Employee e2
ON e1.managerID = e2.id
WHERE e1.salary > e2.salary;

# SELECT E1.Name AS Employee
# FROM Employee AS E1, Employee AS E2 
# WHERE E1.ManagerId = E2.Id AND E1.Salary > E2.Salary