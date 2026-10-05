def count_positives_sum_negatives(arr):
    if not arr:
        return []
    return [len([element for element in arr if element > 0]), sum([element for element in arr if element < 0])]