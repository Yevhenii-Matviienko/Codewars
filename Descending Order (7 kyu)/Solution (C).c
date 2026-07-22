#include <inttypes.h>

uint64_t descendingOrder(uint64_t n) {
    int digits[10] = {0};
    uint64_t result = 0;
    if (n == 0) {
        return 0;
    }
    while (n > 0) {
        digits[n % 10]++;
        n /= 10;
    }
    for (int digit = 9; digit >= 0; digit--) {
        while (digits[digit] > 0) {
            result = result * 10 + digit;
            digits[digit]--;
        }
    }
    return result;
}