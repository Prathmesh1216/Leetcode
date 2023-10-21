# Write your MySQL query statement below
select id, (case when p_id is NULL then "Root" when id in (select id from tree where id in (select p_id from tree))
then "Inner"
 else "Leaf" end) as type from Tree
order by id
