from math import isqrt

def find_next_square(sq):
    nearest_square_root = isqrt(sq)
    return (nearest_square_root + 1) ** 2 if nearest_square_root ** 2 == sq else -1