def string_clean(s):
    return "".join(symbol for symbol in s if not symbol.isdigit())