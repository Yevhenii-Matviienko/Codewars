#include <string>
#include <vector>
#include <utility>

using namespace std;

class RomanHelper {
    public:
        vector<pair<int, string>> decimal_roman_numbers = {
            {1000, "M"},
            {900, "CM"},
            {500, "D"},
            {400, "CD"},
            {100, "C"},
            {90, "XC"},
            {50, "L"},
            {40, "XL"},
            {10, "X"},
            {9, "IX"},
            {5, "V"},
            {4, "IV"},
            {1, "I"}
        };
  
        string to_roman(unsigned int n) {
            string result = "";
            for (auto decimal_roman_pair : decimal_roman_numbers) {
                int decimal_number = decimal_roman_pair.first;
                string roman_number = decimal_roman_pair.second;
                while (n >= decimal_number) {
                    result += roman_number;
                    n -= decimal_number;
                }
            }
            return result;
        }

        int from_roman(string rn) {
            int result = 0;
            int index = 0;
            for (auto decimal_roman_pair : decimal_roman_numbers) {
                int decimal_number = decimal_roman_pair.first;
                string roman_number = decimal_roman_pair.second;
                while (rn.substr(index, roman_number.length()) == roman_number) {
                    result += decimal_number;
                    index += roman_number.length();
                }
            }
            return result;
        }
} RomanNumerals;