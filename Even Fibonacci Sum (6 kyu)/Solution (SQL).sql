WITH RECURSIVE fibonacci(number_1, number_2) AS (
  VALUES (0::BIGINT, 2::BIGINT)
  UNION ALL
  SELECT number_2, number_1 + 4 * number_2
  FROM fibonacci
  WHERE number_2 < 10000000000
)
SELECT DISTINCT n,
  (
    SELECT SUM(number_1)
    FROM (
      SELECT 0::BIGINT AS number_1
      UNION ALL
      SELECT number_1 
      FROM fibonacci 
      WHERE number_1 < n
    ) AS even_fibonacci_numbers
  )::BIGINT AS res
FROM evenfib;