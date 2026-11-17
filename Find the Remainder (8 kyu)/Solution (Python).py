def remainder(a, b):
    big_number, small_number = max(a, b), min(a, b)
    return None if small_number == 0 else big_number % small_number