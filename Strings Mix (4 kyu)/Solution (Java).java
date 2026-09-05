import java.util.*;

public class Mixing {
    public static String mix(String s1, String s2) {
        int[] count_all_symbols_1 = new int[26];
        int[] count_all_symbols_2 = new int[26];
        for (char symbol : s1.toCharArray()) {
            if (symbol >= 'a' && symbol <= 'z') {
                count_all_symbols_1[symbol - 'a']++;
            }
        }
        for (char symbol : s2.toCharArray()) {
            if (symbol >= 'a' && symbol <= 'z') {
                count_all_symbols_2[symbol - 'a']++;
            }
        }
        List<String> result = new ArrayList<>();
        for (int index = 0; index < 26; index++) {
            int max_number_symbol = Math.max(count_all_symbols_1[index], count_all_symbols_2[index]);
            if (max_number_symbol > 1) {
                String prefix = count_all_symbols_1[index] > count_all_symbols_2[index] ? "1:" : count_all_symbols_2[index] > count_all_symbols_1[index] ? "2:" : "=:";
                char letter = (char) ('a' + index);
                result.add(prefix + String.valueOf(letter).repeat(max_number_symbol));
            }
        }
        result.sort((first_result_part, second_result_part) -> first_result_part.length() != second_result_part.length() ? Integer.compare(second_result_part.length(), first_result_part.length()) : first_result_part.compareTo(second_result_part));
        return String.join("/", result);
    }
}