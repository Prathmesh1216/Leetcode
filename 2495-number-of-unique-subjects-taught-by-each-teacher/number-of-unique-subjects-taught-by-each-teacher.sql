# Write your MySQL query statement below
select teacher_id, count(*) as cnt from (
  select distinct teacher_id, subject_id from Teacher
) as t group by teacher_id