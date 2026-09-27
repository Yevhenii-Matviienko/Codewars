SELECT sale.transaction_date::DATE AS day, 
  department.name AS department, 
  COUNT(sale.id)::INT AS sale_count
FROM department
JOIN sale ON department.id = sale.department_id
GROUP BY day, department.name
ORDER BY day ASC;