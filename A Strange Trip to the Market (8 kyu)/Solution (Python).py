def is_loch_ness_monster(string):
    string_lowercase = string.lower()
    return ("three fifty" in string_lowercase) or ("tree fiddy" in string_lowercase) or ("3.50" in string_lowercase)