def abbrev_name(name):
    name, surname = name.split()
    return f"{name[0]}.{surname[0]}".upper()