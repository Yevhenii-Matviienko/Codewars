#include <stdlib.h>
#include <stdio.h>
#include <string.h>

char *range_extraction(const int *args, size_t n) {
    char *result = calloc(n * 24 + 1, 1);
    for (size_t index = 0; index < n; index++) {
        char current_range[48 + 1 + 1];
        size_t start = index;
        while (index + 1 < n && args[index + 1] == args[index] + 1) {
            index++;
        }
        if (start > 0) {
            strcat(result, ",");
        }
        if (index - start >= 2) {
            sprintf(current_range, "%d-%d", args[start], args[index]);
        }  
        else if (index - start == 1) {
            sprintf(current_range, "%d,%d", args[start], args[index]);
        }
        else {
            sprintf(current_range, "%d", args[start]);
        }
        strcat(result, current_range);
    }
    return result;
}