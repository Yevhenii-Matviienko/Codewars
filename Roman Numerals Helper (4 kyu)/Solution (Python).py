class RomanNumerals:
    decimal_roman_numbers = [
        (1000, "M"),
        (900, "CM"),
        (500, "D"),
        (400, "CD"),
        (100, "C"),
        (90, "XC"),
        (50, "L"),
        (40, "XL"),
        (10, "X"),
        (9, "IX"),
        (5, "V"),
        (4, "IV"),
        (1, "I"),
    ]

    @staticmethod
    def to_roman(val: int) -> str:
        result = ""
        for decimal_number, roman_number in RomanNumerals.decimal_roman_numbers:
            while val >= decimal_number:
                result += roman_number
                val -= decimal_number
        return result

    @staticmethod
    def from_roman(roman_num: str) -> int:
        result = 0
        index = 0
        for decimal_number, roman_number in RomanNumerals.decimal_roman_numbers:
            while roman_num[index : index + len(roman_number)] == roman_number:
                result += decimal_number
                index += len(roman_number)
        return result