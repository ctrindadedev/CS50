In 12.sql, write a SQL query to list the titles of all movies in which both Bradley Cooper and Jennifer Lawrence starred.
Your query should output a table with a single column for the title of each movie.
You may assume that there is only one person in the database with the name Bradley Cooper.
You may assume that there is only one person in the database with the name Jennifer Lawrence.

SELECT title
FROM movies
JOIN stars ON movies.id = stars.movie_id
JOIN people ON people.id = star.person_id
WHERE people.name IN ('Bradley Cooper', 'Jennifer Lawrence')
--Agrupar registros que têm valores idênticos em colunas especificadas (apenas organiza)
GROUP BY title
--O número de linhas dentro deste grupo é igual a 2?
HAVING COUNT(title) = 2;

 