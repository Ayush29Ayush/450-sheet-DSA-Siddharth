# Write your MySQL query statement below
# This query uses the `DENSE_RANK()` function to assign a rank to each score based on the order of the scores in descending order. The `ORDER BY` clause sorts the scores in descending order, and the `AS` keyword is used to give a name to the rank column. The `FROM` clause specifies the table containing the scores. The result table is ordered by score in descending order, as specified by the final `ORDER BY` clause. The `OVER` function is to impose the rank on the desc score and is used when dealing with window functions like `DENSE_RANK()`

# for reference => https://www.youtube.com/watch?v=IEaEdvzmz2g

# 3. SELECT score, DENSE_RANK() OVER (ORDER BY score DESC)
# 2. SELECT score, OVER (ORDER BY score DESC)
# 1. FROM scores
# 4. ORDER BY score DESC    // because ques mein desc order mein return karna bola tha

SELECT score, DENSE_RANK() OVER (ORDER BY score DESC) AS 'rank'
FROM scores
ORDER BY score DESC