def get_middle(s):
    middle_symbol_index = len(s) // 2
    return s[middle_symbol_index] if len(s) % 2 else s[middle_symbol_index - 1 : middle_symbol_index + 1]