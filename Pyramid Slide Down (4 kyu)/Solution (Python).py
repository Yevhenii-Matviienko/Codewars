def longest_slide_down(pyramid):
    for row in range(len(pyramid) - 2, -1, -1):
        for column in range(len(pyramid[row])):
            pyramid[row][column] += max(
                pyramid[row + 1][column],
                pyramid[row + 1][column + 1]
            )
    return pyramid[0][0]