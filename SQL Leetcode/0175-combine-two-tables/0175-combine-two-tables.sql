# Write your MySQL query statement below
# -- left join kiya because left side ka sab chahiye but right side ka agar nahi mile toh null kar dena

SELECT firstName, lastName, city, state
FROM Person LEFT JOIN Address 
ON Person.personId = Address.personId

# SELECT firstname, lastname, city, state
# FROM person p LEFT JOIN Address a
# ON p.personId = a.personId