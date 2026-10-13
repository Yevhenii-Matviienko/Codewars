def binary_array_to_number(arr):
    result = 0
    for binary_digit in arr:
        result = (result << 1) | binary_digit
    return result