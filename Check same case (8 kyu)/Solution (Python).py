def same_case(a, b):
    if not (a.isalpha() and b.isalpha()):
        return -1
    return int(a.isupper() == b.isupper())