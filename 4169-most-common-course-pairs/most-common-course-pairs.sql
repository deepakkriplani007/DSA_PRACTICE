/* Write your T-SQL query statement below */
select first_course,second_course,count(*) as transition_count from(
select course_name as first_course,lead(course_name,1) over(partition by user_id order BY completion_date) as second_course     from
(
select user_id,course_name,completion_date from course_completions where user_id in(
select user_id
-- ,count(course_id) as cn,avg(course_rating*1.00) marks
 from course_completions group by user_id having count(course_id)>4 and avg(course_rating*1.00)>=4
 ) 
) t 
) g
where second_course is not null group by first_course,second_course order by transition_count desc,first_course,second_course