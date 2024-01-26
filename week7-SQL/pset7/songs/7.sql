SELECT AVG(energy)
FROM songs
INNER JOIN artists ON songs.artist_id = artists.id
WHERE artist_id = 23;
