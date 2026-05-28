SELECT a,
  b,
  (b - a) / 3 + (b - a) % 3 AS res
FROM jumps;