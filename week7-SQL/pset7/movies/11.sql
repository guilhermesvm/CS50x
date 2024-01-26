SELECT movies.title
FROM movies
INNER JOIN ratings ON ratings.movie_id = movies.id
INNER JOIN stars ON stars.movie_id = movies.id
INNER JOIN people ON stars.person_id = people.id
WHERE people.name = 'Chadwick Boseman'
ORDER BY ratings.rating DESC
LIMIT 5;

