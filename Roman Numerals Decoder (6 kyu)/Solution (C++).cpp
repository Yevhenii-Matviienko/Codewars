#include <string>
#include <map>

using namespace std;

int solution(string roman) {
    map<char, int> roman_decimal_numbers = {
        {'I', 1},
        {'V', 5},
        {'X', 10},
        {'L', 50},
        {'C', 100},
        {'D', 500},
        {'M', 1000}
    };
    int result = 0;
    for (int index = 0; index < roman.length(); index++) {
        int current_decimal_digit = roman_decimal_numbers[roman[index]];
        int next_decimal_digit = 0;
        if (index + 1 < roman.length()) {
            next_decimal_digit = roman_decimal_numbers[roman[index + 1]];
        }
        if (current_decimal_digit < next_decimal_digit) {
            result -= current_decimal_digit;
        } else {
            result += current_decimal_digit;
        }
    }
    return result;
}