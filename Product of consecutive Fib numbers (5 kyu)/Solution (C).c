#include <stdlib.h>

typedef unsigned long long ull;

ull *productFib(ull prod) {
    ull number_1 = 0;
    ull number_2 = 1;
    while (number_1 * number_2 < prod) {
        ull number_3 = number_1 + number_2;
        number_1 = number_2;
        number_2 = number_3;
    }
    ull *result = malloc(3 * sizeof(ull));
    result[0] = number_1;
    result[1] = number_2;
    result[2] = (number_1 * number_2 == prod);
    return result;
}