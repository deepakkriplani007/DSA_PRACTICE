/* Write your T-SQL query statement below */
select author_id as id from views where viewer_id=author_id group by author_id