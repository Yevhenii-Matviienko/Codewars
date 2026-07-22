#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

void high_and_low(const char *strnum, char *result) {
    int min_number = INT_MAX;
    int max_number = INT_MIN;
    while (*strnum != '\0') {
        char *string_end_pointer;
        int number = (int)strtol(strnum, &string_end_pointer, 10);
        if (number > max_number) {
            max_number = number;
        }
        if (number < min_number) {
            min_number = number;
        }
        strnum = string_end_pointer;
    }
    sprintf(result, "%d %d", max_number, min_number);
}