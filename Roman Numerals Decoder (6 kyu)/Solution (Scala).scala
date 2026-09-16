object Roman {
    val roman_decimal_numbers: Map[Char, Int] = Map(
        'I' -> 1,
        'V' -> 5,
        'X' -> 10,
        'L' -> 50,
        'C' -> 100,
        'D' -> 500,
        'M' -> 1000
    )

    def decode(roman: String): Int = {
        var result = 0
        for (index <- roman.indices) {
            val current_decimal_digit = roman_decimal_numbers(roman(index))
            val next_decimal_digit = if (index + 1 < roman.length) roman_decimal_numbers(roman(index + 1)) else 0
            if (current_decimal_digit < next_decimal_digit) {
                result -= current_decimal_digit
            } 
            else {
                result += current_decimal_digit
            }
        }
        return result
    }
}