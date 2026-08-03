#include <string.h>

static const unsigned decimal_numbers[] = {
    1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1
};
static const char *roman_numbers[] = {
    "M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"
};

unsigned from_roman(const char *roman) {
    unsigned result = 0;
    int index_current_roman_number = 0;
    for (int index = 0; index < 13; index++) {
        int roman_digit_length = strlen(roman_numbers[index]);
        while (strncmp(roman + index_current_roman_number, roman_numbers[index], roman_digit_length) == 0) {
            result += decimal_numbers[index];
            index_current_roman_number += roman_digit_length;
        }
    }
    return result;
}

void to_roman(unsigned number, char *roman) {
    roman[0] = '\0';
    for (int index = 0; index < 13; index++) {
        while (number >= decimal_numbers[index]) {
            strcat(roman, roman_numbers[index]);
            number -= decimal_numbers[index];
        }
    }
}