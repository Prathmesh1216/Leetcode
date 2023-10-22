# Write your MySQL query statement below
select distinct l2.num as ConsecutiveNums
from Logs l2
join Logs l1
on l1.num = l2.num and l2.id = l1.id + 1
join Logs l3
on l2.num = l3.num and l2.id + 1 = l3.id
