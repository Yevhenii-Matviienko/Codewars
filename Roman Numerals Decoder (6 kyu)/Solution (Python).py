def solution(roman: str) -> int:
    roman_decimal_numbers = {
        'I': 1,
        'V': 5,
        'X': 10,
        'L': 50,
        'C': 100,
        'D': 500,
        'M': 1000
    }
    result = 0
    for index in range(len(roman)):
        current_decimal_digit = roman_decimal_numbers[roman[index]]
        next_decimal_digit = roman_decimal_numbers[roman[index + 1]] if index + 1 < len(roman) else 0
        if current_decimal_digit < next_decimal_digit:
            result -= current_decimal_digit
        else:
            result += current_decimal_digit
    return result