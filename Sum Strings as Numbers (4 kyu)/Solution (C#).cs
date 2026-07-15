using System;
using System.Text;

public static class Kata {
    public static string sumStrings(string a, string b) {
        int index_1 = a.Length - 1;
        int index_2 = b.Length - 1;
        int carry = 0;
        StringBuilder result = new StringBuilder();
        while (index_1 >= 0 || index_2 >= 0 || carry > 0) {
            int digit_string_1 = index_1 >= 0 ? a[index_1] - '0' : 0;
            int digit_string_2 = index_2 >= 0 ? b[index_2] - '0' : 0;
            int total_digits_sum = digit_string_1 + digit_string_2 + carry;
            result.Append((char)('0' + total_digits_sum % 10));
            carry = total_digits_sum / 10;
            index_1--;
            index_2--;
        }
        char[] characters = result.ToString().ToCharArray();
        Array.Reverse(characters);
        string answer = new string(characters).TrimStart('0');
        return answer == "" ? "0" : answer;
    }
}