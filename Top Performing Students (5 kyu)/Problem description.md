# **Top Performing Students (5 kyu)**

### **Description:**
Let's consider a case where we have a `students` table and a `courses` table. The tables have the following structure:

`students`:
```
| id  | name     | email               |
|-----|----------|---------------------|
| 1   | John     | john@example.com    |
| 2   | Sarah    | sarah@example.com   |
| 3   | Robert   | robert@example.com  |
...
```
`courses`:
```
| id  | student_id | course_name | score |
|-----|------------|-------------|-------|
| 1   | 1          | Math        | 90    |
| 2   | 1          | Science     | 85    |
| 3   | 1          | Physics     | 92    |
| 4   | 1          | Literature  | 80    |
...
```
The educational institution you are working for would like to recognize top performing students in their academics.

In this task, you need to identify students who are outperforming the average score in at least 3 subjects. A student is considered to outperform in a subject if their score is higher than the average score of all students in that subject.

The output of your query should return the following columns:
- `student_id`: The id of the student.
- `name`: The name of the student.
- `outperformance`: An aggregated string in the format subject (percentage), showing the subjects they are outperforming in and the percentage of how much they are outperforming the average. The subjects should be arranged in ascending order by their names.

The percentage of how much a student is outperforming the average in a subject is calculated by the following formula:

`(student's score - average score) / average score * 100%`

This formula calculates the difference between the student's score and the average score, divides that difference by the average score to get a ratio, and then multiplies that ratio by 100 to get a percentage. This percentage shows how much the student's score is above the average score, as a proportion of the average score.

Make sure to round off this percentage to two decimal places for neatness.

Here's a more concrete example:

Assume the average score in Math is 70, and a student scores 90 in Math. The calculation would be:

(90 - 70) / 70 * 100% = 28.57%

So, this student outperforms the average in Math by 28.57%. This means the student's score is 28.57% higher than the average score in Math.

The result should be ordered by `student_id` in asc order.

GLHF!

Desired Output

The desired output should look like this:
| student_id | name | outperformance |
|---:|---|---|
| 1 | John | Literature (15.79%), Math (11.24%), Physics (12.69%), Science (5.65%) |
| 2 | Sarah | Literature (0.69%), Math (13.71%), Physics (5.01%) |
| 4 | Michael | Literature (10.76%), Math (8.76%), Physics (6.29%) |

### **Tags:**
- SQL
- Databases