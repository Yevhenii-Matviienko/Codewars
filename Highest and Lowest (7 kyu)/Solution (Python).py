def high_and_low(numbers):
    list_int_numbers = [int(number) for number in numbers.split()]
    return f"{max(list_int_numbers)} {min(list_int_numbers)}"