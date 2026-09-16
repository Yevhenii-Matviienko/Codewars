class RomanNumerals {
    private val decimal_roman_numbers: List[(Int, String)] = List(
        1000 -> "M",
        900 -> "CM",
        500 -> "D",
        400 -> "CD",
        100 -> "C",
        90 -> "XC",
        50 -> "L",
        40 -> "XL",
        10 -> "X",
        9 -> "IX",
        5 -> "V",
        4 -> "IV",
        1 -> "I"
    )

    def toRoman(number: Int): String = {
        var input_decimal_number = number
        var result = ""
        for ((decimal_number, roman_number) <- decimal_roman_numbers) {
            while (input_decimal_number >= decimal_number) {
                result += roman_number
                input_decimal_number -= decimal_number
            }
        }
        return result
    }

    def fromRoman(roman: String): Int = {
        var index = 0
        var result = 0
        for ((decimal_number, roman_number) <- decimal_roman_numbers) {
            while (roman.slice(index, index + roman_number.length) == roman_number) {
                result += decimal_number
                index += roman_number.length
            }
        }
        return result
    }
}