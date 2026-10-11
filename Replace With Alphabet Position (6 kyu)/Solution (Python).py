def alphabet_position(text):
    result = []
    for letter in text.lower():
        if "a" <= letter <= "z":
            result.append(str(ord(letter) - 96))
    return " ".join(result)