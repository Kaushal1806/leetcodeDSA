# Write your MySQL query statement below
select b.id
from weather a,weather b
where a. temperature<b. temperature
and datediff(b.recordDate, a.recordDate) = 1