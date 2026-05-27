SELECT n, 
  CASE
    WHEN n > 0 
    THEN n * (n + 1) / 2
    ELSE 0
  END AS res
FROM triangular;