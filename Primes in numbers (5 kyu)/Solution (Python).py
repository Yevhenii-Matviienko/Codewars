def prime_factors(n):
    result = ''
    divisor = 2
    while divisor * divisor <= n:
        count_divisions = 0
        while n % divisor == 0:
            count_divisions += 1
            n //= divisor
        if count_divisions == 1:
            result += f'({divisor})'
        elif count_divisions > 1:
            result += f'({divisor}**{count_divisions})'
        divisor += 1
    if n > 1:
        result += f'({n})'
    return result