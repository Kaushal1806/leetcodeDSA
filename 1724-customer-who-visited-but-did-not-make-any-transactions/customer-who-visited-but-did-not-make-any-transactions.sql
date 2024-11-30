# Write your MySQL query statement below
select v.customer_id,count(v.visit_id) as count_no_trans
from visits v left join transactions t On v.visit_id = t.visit_id
where t.transaction_id is null 
group by v.customer_id

# after group by , dont apply count function on column having null values
# so count(t.transaction_id) does not work