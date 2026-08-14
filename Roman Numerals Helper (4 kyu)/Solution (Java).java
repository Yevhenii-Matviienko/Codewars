public class RomanNumerals {
    private static final int[] decimal_numbers = {
        1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1
    };
    private static final String[] roman_numbers = {
        "M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"
    };

    public static String toRoman(int n) {
        StringBuilder result = new StringBuilder();
        for (int index = 0; index < decimal_numbers.length; index++) {
            while (n >= decimal_numbers[index]) {
                result.append(roman_numbers[index]);
                n -= decimal_numbers[index];
            }
        }
        return result.toString();
    }

    public static int fromRoman(String romanNumeral) {
        int result = 0;
        int index_current_roman_number = 0;
        for (int index = 0; index < roman_numbers.length; index++) {
            while (romanNumeral.startsWith(roman_numbers[index], index_current_roman_number)) {
                result += decimal_numbers[index];
                index_current_roman_number += roman_numbers[index].length();
            }
        }
        return result;
    }
}