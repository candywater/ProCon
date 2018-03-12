# Write your MySQL query statement below
select Name as Employee
from Employee e1
where Salary >
(
  select Salary
  from Employee e2
  where e2.Id = e1.ManagerId
)
