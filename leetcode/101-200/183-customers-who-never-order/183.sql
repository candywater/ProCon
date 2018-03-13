# Write your MySQL query statement below
select c1.Name as Customers
from Customers c1
left outer join
(
  select CustomerId
  from Orders
)o1
on o1.CustomerId = c1.Id
where o1.CustomerId is NULL
