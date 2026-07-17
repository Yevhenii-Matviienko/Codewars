using System;
using System.Linq;
using System.Collections.Generic;

public class Mixing {
    public static string Mix(string s1, string s2) {
        int[] count_symbols_1 = new int[26];
        int[] count_symbols_2 = new int[26];
        foreach (char symbol in s1) {
            if (symbol >= 'a' && symbol <= 'z') {
                count_symbols_1[symbol - 'a']++;
            } 
        }
        foreach (char symbol in s2) {
            if (symbol >= 'a' && symbol <= 'z') {
                count_symbols_2[symbol - 'a']++;
            }
        }
        var result_parts = new List<string>();
        for (int index = 0; index < 26; index++)
        {
            int max_count_symbol = Math.Max(count_symbols_1[index], count_symbols_2[index]);
            if (max_count_symbol <= 1) {
                continue;
            }
            string prefix;
            if (count_symbols_1[index] > count_symbols_2[index]) {
                prefix = "1:";
            }
            else if (count_symbols_2[index] > count_symbols_1[index]) {
                prefix = "2:";
            }
            else {
                prefix = "=:";
            }
            char letter = (char)('a' + index);
            result_parts.Add(prefix + new string(letter, max_count_symbol));
        }
        return string.Join("/",
            result_parts.OrderByDescending(result_part => result_part.Length)
            .ThenBy(result_part => result_part, StringComparer.Ordinal));
    }
}