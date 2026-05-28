SELECT ph.n,
  MAX(h) AS res
FROM pyramidheight AS ph
JOIN generate_series(1, FLOOR(SQRT(ph.n))::int) AS h 
  ON h * (h + 1) * (2 * h + 1) / 6 <= ph.n
GROUP BY ph.n
ORDER BY ph.n ASC;