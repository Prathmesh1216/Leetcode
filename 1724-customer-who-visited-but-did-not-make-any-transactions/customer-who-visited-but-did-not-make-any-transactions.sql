# Write your MySQL query statement below
select Visits.customer_id, count(visit_id) as count_no_trans
from Visits
left join Transactions using(visit_id)
where transaction_id is null group by customer_id