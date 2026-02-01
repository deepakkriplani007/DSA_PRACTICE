/* Write your T-SQL query statement below */
with cte as(select user_id,reaction,
count(reaction) over(partition by user_id,reaction) as cn,
count(reaction) over(partition by user_id) as total
 from reactions
)
select user_id,reaction dominant_reaction ,round(cast(cn as float)/cast(total as float),2) as reaction_ratio from
 cte
where total>4 and cn*1.00/total>=0.60
 group by user_id,reaction,cn,total 
 order by reaction_ratio desc,user_id