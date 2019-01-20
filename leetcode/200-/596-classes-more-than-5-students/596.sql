# Write your MySQL query statement below
select class
from
(
  select class, student
  from courses c0
  group by student, class
) c1
group by class
having count(class) >=5
