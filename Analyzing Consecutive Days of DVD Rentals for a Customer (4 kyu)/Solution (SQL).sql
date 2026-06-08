WITH rental_days AS (
  SELECT DISTINCT c.first_name || ' ' || c.last_name AS name,
    r.rental_date::DATE AS date_rental_occurred
  FROM rental r
  JOIN customer c USING(customer_id)
  WHERE customer_id = 1
),
grouped_rental_days AS (
  SELECT *,
    date_rental_occurred - ROW_NUMBER() OVER (ORDER BY date_rental_occurred)::INT AS dates_groups
  FROM rental_days
)
SELECT name,
  date_rental_occurred,
  COUNT(*) OVER (PARTITION BY dates_groups) AS consecutive_days
FROM grouped_rental_days
ORDER BY date_rental_occurred;