def narcissistic(value):
    sum = 0
    digits = str(value)
    for digit in digits:
        sum += int(digit) ** len(digits)
    return sum == value