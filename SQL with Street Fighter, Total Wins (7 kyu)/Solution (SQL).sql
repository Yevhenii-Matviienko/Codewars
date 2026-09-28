SELECT fighters.name, SUM(fighters.won) AS won, SUM(fighters.lost) AS lost
FROM fighters
JOIN winning_moves ON winning_moves.id = fighters.move_id
WHERE winning_moves.move NOT IN ('Hadoken', 'Shouoken', 'Kikoken')
GROUP BY fighters.name
ORDER BY won DESC
LIMIT 6;