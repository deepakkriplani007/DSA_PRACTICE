WITH base AS (
    SELECT 
        user_id,
        event_type,
        event_date,
        monthly_amount,
        plan_name,
        FIRST_VALUE(plan_name) OVER (
            PARTITION BY user_id 
            ORDER BY event_date DESC
        ) AS last_plan,
        FIRST_VALUE(monthly_amount) OVER (
            PARTITION BY user_id 
            ORDER BY event_date DESC
        ) AS current_plan 
    FROM subscription_events
),
cte AS (
    SELECT
        user_id,
        MIN(CASE WHEN event_type = 'start' THEN event_date END) AS start_date,
        MAX(monthly_amount) AS hismax,
        MAX(event_date) AS lastdate,
        SUM(CASE WHEN event_type = 'downgrade' THEN 1 ELSE 0 END) AS total_downgrade,
        MAX(last_plan) AS last_plan,
        min(current_plan) as current_plan  
    FROM base
    GROUP BY user_id
)

SELECT user_id,last_plan current_plan,current_plan current_monthly_amount,hismax max_historical_amount,datediff(day,start_date,lastdate) as days_as_subscriber 
FROM cte
where total_downgrade>0 and current_plan!=0 and current_plan*1.00/hismax<.5 and datediff(day,start_date,lastdate)>59
order by days_as_subscriber desc,user_id 