def dig_pow(n, p):
    sum = 0
    for digit in str(n):
        sum += int(digit) ** p
        p += 1
    return sum // n if sum % n == 0 else -1