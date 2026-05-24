def array_diff(a, b):
    return [array_element for array_element in a if array_element not in set(b)]