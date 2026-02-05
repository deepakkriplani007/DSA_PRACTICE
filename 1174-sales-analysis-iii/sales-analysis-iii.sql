/* Write your T-SQL query statement below */
with cte as(
select product_id,sum(case when sale_date>='2019-01-01'and sale_date<='2019-03-31' then 1 else 0 end) as siq,sum(case when sale_date<'2019-01-01'or sale_date>'2019-03-31' then 1 else 0 end) as nsiq
from sales group by product_id having SUM(CASE 
            WHEN sale_date >= '2019-01-01' 
             AND sale_date <= '2019-03-31' 
            THEN 1 ELSE 0 
        END) != 0
AND
    SUM(CASE 
            WHEN sale_date < '2019-01-01' 
              OR sale_date > '2019-03-31' 
            THEN 1 ELSE 0 
        END) = 0
)
select p.product_id,p.product_name from product p join cte c on p.product_id=c.product_id