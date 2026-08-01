#include <stdlib.h>
#include <string.h>

char *strsum(const char *a, const char *b) {
    int index_1 = strlen(a) - 1;
    int index_2 = strlen(b) - 1;
    int carry = 0;
    int result_length = (index_1 > index_2 ? index_1 : index_2) + 2;
    char *result = malloc(result_length + 1);
    result[result_length] = '\0';
    while (result_length > 0) {
        int digit_string_1 = index_1 >= 0 ? a[index_1--] - '0' : 0;
        int digit_string_2 = index_2 >= 0 ? b[index_2--] - '0' : 0;
        int sum = digit_string_1 + digit_string_2 + carry;
        result[--result_length] = sum % 10 + '0';
        carry = sum / 10;
    }
    while (result[0] == '0' && result[1] != '\0') {
        memmove(result, result + 1, strlen(result));
    }
    return result;
}