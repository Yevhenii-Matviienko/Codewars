def sort_array(source_array):
    odd_numbers = sorted(element for element in source_array if element % 2)
    return [odd_numbers.pop(0) if element % 2 else element for element in source_array]