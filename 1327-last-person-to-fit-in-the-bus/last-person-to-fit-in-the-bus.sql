select top 1 person_name from 
(select turn,person_name,weight,sum(weight)over(order by turn)
 as nw from queue)
  t 
  where t.nw<=1000 order by t.nw desc
