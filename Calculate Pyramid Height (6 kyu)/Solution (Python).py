def pyramid_height(n):
    height = 0
    while n >= (height + 1) ** 2:
        height += 1
        n -= height ** 2
    return height