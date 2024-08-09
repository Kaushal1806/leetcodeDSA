# Write your MySQL query statement below
delete p from Person p , person q where p.email = q.email and q.id<p.id;