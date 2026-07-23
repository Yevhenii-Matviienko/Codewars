#include <stddef.h>
#include <stdlib.h>

int *array_diff(const int a[], size_t n1, const int b[], size_t n2, size_t *z) {
    int *result = malloc(n1 * sizeof(int));
    *z = 0;
    for (size_t index_1 = 0; index_1 < n1; index_1++) {
        int element_a_exists_in_b = 0;
        for (size_t index_2 = 0; index_2 < n2; index_2++) {
            if (a[index_1] == b[index_2]) {
                element_a_exists_in_b = 1;
            }
        }
        if (!element_a_exists_in_b) {
            result[*z] = a[index_1];
            (*z)++;
        }
    }
    return result;
}