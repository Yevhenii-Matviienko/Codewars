using System.Collections.Generic;

public class RomanDecode {
    public static int Solution(string roman) {
        var roman_decimal_numbers = new Dictionary<char, int> {
            {'I', 1},
            {'V', 5},
            {'X', 10},
            {'L', 50},
            {'C', 100},
            {'D', 500},
            {'M', 1000}
        };
        int result = 0;
        for (int index = 0; index < roman.Length; index++) {
            int current_decimal_digit = roman_decimal_numbers[roman[index]];
            if (index + 1 < roman.Length && current_decimal_digit < roman_decimal_numbers[roman[index + 1]]) {
                result -= current_decimal_digit;
            }
            else {
                result += current_decimal_digit;
            }
        }
        return result;
    }
}