def dir_reduc(arr):
    opposites_directions = {
        "NORTH": "SOUTH",
        "SOUTH": "NORTH",
        "EAST": "WEST",
        "WEST": "EAST"
    }
    result = []
    for direction in arr:
        if result and opposites_directions[direction] == result[-1]:
            result.pop()
        else:
            result.append(direction)
    return result