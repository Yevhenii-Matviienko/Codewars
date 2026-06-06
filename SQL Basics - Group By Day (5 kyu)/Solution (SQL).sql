SELECT created_at::DATE AS day,
  description,
  COUNT(*) AS count
FROM events
WHERE name = 'trained'
GROUP BY created_at::DATE, description
ORDER BY day;