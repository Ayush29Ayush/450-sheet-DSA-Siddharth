# Write your MySQL query statement below
# for reference => https://www.youtube.com/watch?v=OBxq2iuRVxw


# Always start your query using FROM  
# Think of department wala example where show something respective to each department

# first from then group by then having count, then select
SELECT email 
FROM Person
GROUP BY email
HAVING COUNT(DISTINCT id) > 1; # with GROUP BY, we cannot use where so we use HAVING 
# COUNT(id) > 1      condition for duplicates

# distinct naa bhi likho toh chalega since id is primary key which is always unique