SELECT id,
  name
FROM departments
WHERE EXISTS (
  SELECT 1
  FROM sales
  WHERE sales.department_id = departments.id
    AND sales.price > 98.00
);