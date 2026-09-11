def duplicateEncode(word: String): String = {
    val word_lowercase = word.toLowerCase
    return word_lowercase.map(symbol => if (word_lowercase.count(_ == symbol) > 1) ')' else '(')
}