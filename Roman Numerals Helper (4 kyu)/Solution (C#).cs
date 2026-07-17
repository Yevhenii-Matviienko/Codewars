public class RomanNumerals {
    private static readonly (int decimal_number, string roman_number)[] decimal_roman_numbers = {
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
        (1, "I")
    };

    public static string ToRoman(int n) {
        string result = "";
        foreach (var pair in decimal_roman_numbers) {
            while (n >= pair.decimal_number) {
                result += pair.roman_number;
                n -= pair.decimal_number;
            }
        }
        return result;
    }

    public static int FromRoman(string romanNumeral) {
        int result = 0;
        int index = 0;
        foreach (var pair in decimal_roman_numbers) {
            while (index + pair.roman_number.Length <= romanNumeral.Length &&
                romanNumeral.Substring(index, pair.roman_number.Length) == pair.roman_number) {
                result += pair.decimal_number;
                index += pair.roman_number.Length;
            }
        }
        return result;
    }
}