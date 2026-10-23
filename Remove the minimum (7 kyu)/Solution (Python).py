def remove_smallest(numbers):
    numbers_array = numbers[:]
    if numbers_array:
        numbers_array.remove(min(numbers_array))
    return numbers_array