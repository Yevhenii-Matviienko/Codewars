#include <stdlib.h>
#include <stdio.h>

char *factors(int n) {
    char *result = malloc(256);
    int position = 0;
    int divisor = 2;
    while (divisor * divisor <= n) {
        int count_divisions = 0;
        while (n % divisor == 0) {
            count_divisions++;
            n /= divisor;
        }
        if (count_divisions == 1) {
            position += sprintf(result + position, "(%d)", divisor);
        } 
        else if (count_divisions > 1) {
            position += sprintf(result + position, "(%d**%d)", divisor, count_divisions);
        }
        divisor++;
    }
    if (n > 1) {
        position += sprintf(result + position, "(%d)", n);
    }
    return result;
}