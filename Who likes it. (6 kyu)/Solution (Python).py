def likes(names):
    number_names = len(names)
    if number_names == 0:
        return "no one likes this"
    if number_names == 1:
        return f"{names[0]} likes this"
    if number_names == 2:
        return f"{names[0]} and {names[1]} like this"
    if number_names == 3:
        return f"{names[0]}, {names[1]} and {names[2]} like this"
    return f"{names[0]}, {names[1]} and {number_names - 2} others like this"