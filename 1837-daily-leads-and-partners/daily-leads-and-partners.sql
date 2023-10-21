# Write your MySQL query statement below
select d1.date_id, d2.make_name, count(distinct(d1.lead_id)) as unique_leads, count(distinct(d1.partner_id)) as unique_partners
from DailySales d1
cross join DailySales d2
on d1.date_id = d2.date_id and d1.make_name = d2.make_name
group by d1.date_id, d2.make_name
