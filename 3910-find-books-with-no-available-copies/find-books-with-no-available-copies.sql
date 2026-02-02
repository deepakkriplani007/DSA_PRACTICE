/* Write your T-SQL query statement below */
with cte as (select book_id,count(*) as cn from borrowing_records
where return_date is null group by book_id)
select a.book_id,title,author,genre,publication_year,total_copies as current_borrowers                              
 from library_books a join cte b on a.book_id=b.book_id where a.total_copies=b.cn
 order by current_borrowers desc,title