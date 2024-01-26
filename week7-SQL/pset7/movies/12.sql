SELECT movies.title
FROM movies
INNER JOIN stars AS star1 ON star1.movie_id = movies.id
INNER JOIN people AS people1 ON star1.person_id = people1.id
INNER JOIN stars AS star2 ON star2.movie_id = movies.id
INNER JOIN people AS people2 ON star2.person_id = people2.id
WHERE people1.name = 'Bradley Cooper'
AND people2.name = 'Jennifer Lawrence';
