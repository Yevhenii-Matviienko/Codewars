#include <stdlib.h>
#include <string.h>

typedef char Pair[2];

Pair *split_2(const char *s, size_t *n) {
    *n = (strlen(s) + 1) / 2;
    Pair *result = malloc(*n * sizeof(Pair));
    for (size_t index = 0; index < *n; index++) {
        result[index][0] = s[index * 2];
        result[index][1] = s[index * 2 + 1] ? s[index * 2 + 1] : '_';
    }
    return result;
}