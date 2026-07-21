#include <stdio.h>
#include <math.h>

int digPow(int n, int p) {
    char digits[20];
    sprintf(digits, "%d", n);
    long long sum = 0;
    for (int index = 0; digits[index] != '\0'; index++) {
        int digit = digits[index] - '0';
        sum += (long long)pow(digit, p);
        p++;
    }
    return sum % n == 0 ? (int)(sum / n) : -1;
}