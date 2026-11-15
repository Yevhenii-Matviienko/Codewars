def sum_of_differences(arr):
    numbers_array_sorted = sorted(arr, reverse=True)
    return sum(numbers_array_sorted[index] - numbers_array_sorted[index + 1] for index in range(len(numbers_array_sorted) - 1))