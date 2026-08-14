public class Kata {
    public static String sumStrings(String a, String b) {
        int index_1 = a.length() - 1;
        int index_2 = b.length() - 1;
        int carry = 0;
        StringBuilder result = new StringBuilder();
        while (index_1 >= 0 || index_2 >= 0 || carry > 0) {
            int digit_string_1 = index_1 >= 0 ? a.charAt(index_1) - '0' : 0;
            int digit_string_2 = index_2 >= 0 ? b.charAt(index_2) - '0' : 0;
            int total_digits_sum = digit_string_1 + digit_string_2 + carry;
            result.append(total_digits_sum % 10);
            carry = total_digits_sum / 10;
            index_1--;
            index_2--;
        }
        result.reverse();
        int number_start = 0;
        while (number_start < result.length() - 1 && result.charAt(number_start) == '0') {
            number_start++;
        }
        return result.length() == 0 ? "0" : result.substring(number_start);
    }
}