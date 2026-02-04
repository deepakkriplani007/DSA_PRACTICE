/* Write your T-SQL query statement below */
-- select user_id,session_id,datediff('minute',),sum(case when event_type='scroll'then 1 else 0 end) as scroll_count from app_events group by user_id,session_id,event_type
select session_id,user_id,session_duration_minutes ,scroll_count  from
(select session_id,user_id,
datediff(
minute,
MIN(case when event_type='app_open' then event_timestamp end) ,
MAX(case when event_type='app_close' then event_timestamp end)
)as session_duration_minutes ,
sum(case when event_type='scroll'then 1 else 0 end) as scroll_count,
sum(case when event_type='click'then 1 else 0 end) as click_count
from app_events 
group by user_id,session_id) t
where scroll_count>=5 and session_duration_minutes>=30 and(click_count*1.00/scroll_count)<0.2 and session_id  not in(select session_id from app_events where event_type ='purchase')
order by scroll_count  desc,session_id