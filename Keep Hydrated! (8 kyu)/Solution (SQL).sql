SELECT id, hours, FLOOR(hours * 0.5)::INT AS liters
FROM cycling;