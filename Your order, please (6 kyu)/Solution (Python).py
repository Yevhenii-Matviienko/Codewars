def order(sentence):
    words = sentence.split()
    result = [""] * len(words)
    for word in words:
        word_position = int(next(symbol for symbol in word if symbol.isdigit()))
        result[word_position - 1] = word
    return " ".join(result)