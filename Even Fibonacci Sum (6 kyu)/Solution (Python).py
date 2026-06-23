def even_fib(n):
    number_1, number_2 = 0, 1
    total_sum = 0
    while number_1 < n:
        if number_1 % 2 == 0:
            total_sum += number_1
        number_1, number_2 = number_2, number_1 + number_2
    return total_sum