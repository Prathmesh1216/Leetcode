# Write your MySQL query statement below
select Weather.id from Weather
join Weather w
where datediff(Weather.recordDate,w.recordDate) = 1
and w.temperature<Weather.temperature