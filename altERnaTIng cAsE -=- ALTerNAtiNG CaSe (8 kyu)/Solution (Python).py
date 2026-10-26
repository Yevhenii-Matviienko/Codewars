def to_alternating_case(string):
    return "".join(symbol.lower() if symbol.isupper() else 
        symbol.upper() if symbol.islower() else symbol 
        for symbol in string)