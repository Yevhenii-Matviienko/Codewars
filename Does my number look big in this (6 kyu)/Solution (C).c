#include <stdbool.h>
#include <math.h>

bool narcissistic(int num) {
    int sum = 0;
    int number = num;
    int digits = 0;
    for (int number = num; number > 0; number /= 10) {
        digits++;
    }
    number = num;
    while (number > 0) {
        sum += pow(number % 10, digits);
        number /= 10;
    }
    return sum == num;
}