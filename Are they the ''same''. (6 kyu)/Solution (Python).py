def comp(array1, array2):
    if array1 is None or array2 is None:
        return False
    return sorted(element * element for element in array1) == sorted(array2)