def get_grade(s1, s2, s3):
    average_score = (s1 + s2 + s3) / 3
    if average_score >= 90:
        return "A"
    if average_score >= 80:
        return "B"
    if average_score >= 70:
        return "C"
    if average_score >= 60:
        return "D"
    return "F"