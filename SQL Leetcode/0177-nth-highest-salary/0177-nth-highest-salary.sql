CREATE FUNCTION getNthHighestSalary(N INT) RETURNS INT
BEGIN
DECLARE M INT;
SET M = N-1;
  RETURN (
      # Write your MySQL query statement below.
      # SELECT salary 
      # FROM Employee
      # ORDER BY salary DESC LIMIT N-1, 1
#     You have an error in your SQL syntax; check the manual that corresponds to your MySQL server version for the right syntax to use near '-1, 1
#      -1 esse beech mein use nahi kar sakte isiliye pehle se hi declare karke set karlo
      # SELECT salary     // isse NULL consider nahi hoga and wrong ans ayega
      SELECT DISTINCT salary
      FROM Employee
      ORDER BY salary DESC LIMIT M,1
  );
END