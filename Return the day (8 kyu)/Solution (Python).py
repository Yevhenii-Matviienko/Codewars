def whatday(num):
    days_week = ["Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"]
    return days_week[num - 1] if 1 <= num <= 7 else "Wrong, please enter a number between 1 and 7"