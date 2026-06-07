SELECT c.id AS category_id,
  c.category,
  p.title,
  p.views,
  p.id AS post_id
FROM categories c
LEFT JOIN LATERAL (
  SELECT *
  FROM posts p
  WHERE p.category_id = c.id
  ORDER BY p.views DESC, 
    p.id
  LIMIT 2
) p ON TRUE
ORDER BY c.category, 
  p.views 
  DESC, p.id;