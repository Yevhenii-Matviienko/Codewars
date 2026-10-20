def count_sheep(n):
    result = ""
    for index in range(1, n + 1):
        result += f"{index} sheep..."
    return result