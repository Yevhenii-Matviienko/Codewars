package mix

fun mix(s1: String, s2: String): String {
    val count_all_symbols_1 = IntArray(26)
    val count_all_symbols_2 = IntArray(26)
    for (symbol in s1) {
        if (symbol in 'a'..'z') {
            count_all_symbols_1[symbol - 'a']++
        }
    }
    for (symbol in s2) {
        if (symbol in 'a'..'z') {
            count_all_symbols_2[symbol - 'a']++
        }
    }
    val result = mutableListOf<String>()
    for (index in 0 until 26) {
        val number_symbol_1 = count_all_symbols_1[index]
        val number_symbol_2 = count_all_symbols_2[index]
        val max_number_symbol = maxOf(number_symbol_1, number_symbol_2)
        if (max_number_symbol <= 1) { 
            continue
        }
        val prefix = when {
            number_symbol_1 > number_symbol_2 -> "1:"
            number_symbol_2 > number_symbol_1 -> "2:"
            else -> "=:"
        }
        val letter = 'a' + index
        result.add(prefix + letter.toString().repeat(max_number_symbol))
    }
    return result.sortedWith(compareByDescending<String> { element -> element.length }.thenBy { element -> element }).joinToString("/")
}