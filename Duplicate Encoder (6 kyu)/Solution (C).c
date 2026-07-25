#include <stdlib.h>
#include <ctype.h>
#include <string.h>

char *DuplicateEncoder(const char *string) {
    size_t string_length = strlen(string);
    char *result = malloc(string_length + 1);
    for (size_t index_1 = 0; index_1 < string_length; index_1++) {
        char symbol = tolower((unsigned char)string[index_1]);
        int symbol_count = 0;
        for (size_t index_2 = 0; index_2 < string_length; index_2++) {
            if (tolower((unsigned char)string[index_2]) == symbol) {
                symbol_count++;
            }
        }
        result[index_1] = (symbol_count > 1) ? ')' : '(';
    }
    result[string_length] = '\0';
    return result;
}