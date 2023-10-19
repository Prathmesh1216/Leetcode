# Write your MySQL query statement below
select SalesPerson.name from SalesPerson
where SalesPerson.name not in
(
    select SalesPerson.name from SalesPerson
    left join Orders on SalesPerson.sales_id = Orders.sales_id
    left join Company on Orders.com_id = Company.com_id
    where Company.name = "RED"
)