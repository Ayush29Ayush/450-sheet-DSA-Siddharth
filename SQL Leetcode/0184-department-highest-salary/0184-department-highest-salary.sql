# Write your MySQL query statement below
# refer this => https://leetcode.com/problems/department-highest-salary/discuss/2457422/Solution-with-Detail-Explanation-(Easy-to-Understand)

# MY SOLUTION => ismein har dept ka highest de raha tha, ek dept ke 2 max nahi de raha tha
# SELECT d.name AS Department , e.name AS Employee , MAX(e.salary) AS Salary 
# FROM Employee e
# LEFT JOIN Department d
# ON e.departmentId = d.id
# GROUP BY d.id


# 1. SELECT departmentId, MAX(salary) FROM Employee GROUP BY departmentId

# 2. SELECT Department.name AS Department ,Employee.name AS Employee, Employee.salary
#    FROM Department  JOIN Employee  ON Employee.departmentId=Department.id

# 3. WHERE(departmentId, salary) IN (SELECT departmentId,MAX(salary) FROM Employee GROUP BY departmentId)

SELECT Department.name AS Department ,Employee.name AS Employee, Employee.salary
FROM Department 
JOIN Employee 
ON Employee.departmentId=Department.id 
WHERE(departmentId, salary) IN (SELECT departmentId,MAX(salary) FROM Employee GROUP BY departmentId) ;
