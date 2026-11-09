def sum_mul(n, m):
    if (n <= 0) or (m <= 0):
        return "INVALID"
    l = (m - 1) // n         
    return n * l * (l + 1) // 2