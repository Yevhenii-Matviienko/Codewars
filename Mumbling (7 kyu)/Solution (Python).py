def accum(st):
    return "-".join(letter.upper() + letter.lower() * index for index, letter in enumerate(st))