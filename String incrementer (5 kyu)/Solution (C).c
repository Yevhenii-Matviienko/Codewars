#include <stdlib.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

char *incrementString(const char *str) {
    int string_length = strlen(str);
    int index = string_length;
    while (index > 0 && isdigit((unsigned char)str[index - 1])) {
        index--;
    }
    int number_length = string_length - index;
    char *result = malloc(string_length + 2);
    if (number_length == 0) {
        sprintf(result, "%s1", str);
        return result;
    }
    long number = atol(str + index) + 1;
    memcpy(result, str, index);
    sprintf(result + index, "%0*ld", number_length, number);
    return result;
}