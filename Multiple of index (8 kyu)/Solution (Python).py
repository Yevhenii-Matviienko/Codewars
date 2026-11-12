def multiple_of_index(arr):
    return [element for index, element in enumerate(arr) if (element == 0) or (index != 0 and element % index == 0)]