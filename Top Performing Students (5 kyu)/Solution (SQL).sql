WITH students_courses_scores AS (
  SELECT s.id student_id,
    s.name,
    c.course_name, 
    c.score,
    AVG(c.score) OVER (PARTITION BY c.course_name) average_score
  FROM students s 
  JOIN courses c ON c.student_id = s.id
)
SELECT student_id,
  name,
  STRING_AGG(course_name || ' (' || ROUND(((score - average_score) / average_score * 100), 2) || '%)', ', ' ORDER BY course_name) outperformance
FROM students_courses_scores
WHERE score > average_score
GROUP BY student_id, 
  name
HAVING COUNT(*) >= 3
ORDER BY student_id;