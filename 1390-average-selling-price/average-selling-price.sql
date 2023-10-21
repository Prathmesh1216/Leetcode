select Prices.product_id, ifnull(ROUND(SUM(us.units*price)/sum(units),2),0) as average_price
from Prices
LEFT JOIN UnitsSold us
on Prices.product_id = us.product_id AND
us.purchase_date between start_date and end_date
GROUP BY Prices.product_id;

