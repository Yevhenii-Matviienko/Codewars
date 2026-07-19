#include <stdbool.h>
#include <math.h>

bool is_square(int n) {
    if (n < 0) {
        return false;
    }
    int square_root = (int)sqrt(n);
    return (square_root * square_root) == n;
}