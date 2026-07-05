#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Mix {
    public:
        static string mix(const string &s1, const string &s2) {
            vector<int> count_chars_string_1(26, 0);
            vector<int> count_chars_string_2(26, 0);
            for (char char_string_1 : s1) {
                if (char_string_1 >= 'a' && char_string_1 <= 'z') {
                    count_chars_string_1[char_string_1 - 'a']++;
                }
            }
            for (char char_string_2 : s2) {
                if (char_string_2 >= 'a' && char_string_2 <= 'z') {
                    count_chars_string_2[char_string_2 - 'a']++;
                }
            }
            vector<string> result_parts;
            for (int index = 0; index < 26; index++) {
                int number_char_string_1 = count_chars_string_1[index];
                int number_char_string_2 = count_chars_string_2[index];
                int max_number_char = max(number_char_string_1, number_char_string_2);
                if (max_number_char <= 1) {
                    continue;
                }
                char current_char = static_cast<char>('a' + index);
                string result_part;
                if (number_char_string_1 > number_char_string_2) {
                    result_part = "1:";
                } 
                else if (number_char_string_2 > number_char_string_1) {
                    result_part = "2:";
                } 
                else {
                    result_part = "=:";
                }
                result_part += string(max_number_char, current_char);
                result_parts.push_back(result_part);
            }
            sort(result_parts.begin(), result_parts.end(),
                [](const string &element_1, const string &element_2) {
                    if (element_1.length() != element_2.length()) {
                        return element_1.length() > element_2.length();
                    }
                    return element_1 < element_2;
                });
            string result;
            for (size_t index = 0; index < result_parts.size(); index++) {
                if (index > 0) {
                    result += "/";
                }
                result += result_parts[index];
            }
            return result;
        }
};