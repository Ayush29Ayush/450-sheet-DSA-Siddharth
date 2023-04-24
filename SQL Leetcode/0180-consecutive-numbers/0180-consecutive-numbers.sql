# Write your MySQL query statement below

# Here we will use new window function called LEAD() which gives us the consecutive X units forward's ans.
# and since window func use kar rahe toh OVER() bhi use hoga
# humme voh number chahiye jiska present bhi N ho, next wala bhi N ho and next to next wala bhi N ho. 3 consecutive number same ho toh return karna hai\

# for reference => https://www.youtube.com/watch?v=iNaLjT9ybYI


# 2. WITH newtable AS
# 1. (SELECT *, LEAD(num,1) OVER() AS next1, LEAD(num,2) OVER() AS next2next FROM Logs)

WITH newtable AS
(SELECT *, LEAD(num,1) OVER() AS next1, LEAD(num,2) OVER() AS next2next FROM Logs)

# 3. neeche ka pura
SELECT DISTINCT num AS ConsecutiveNums
FROM newtable
WHERE num = next1 
AND num = next2next

