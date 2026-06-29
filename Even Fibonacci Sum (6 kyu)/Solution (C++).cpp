unsigned long long fibonacci(unsigned long long max) {
    unsigned long long number_1 = 0;
    unsigned long long number_2 = 1;
    unsigned long long total_sum = 0;
    while (number_1 < max) {
        if (number_1 % 2 == 0) {
            total_sum += number_1;
        }
        unsigned long long number_3 = number_1 + number_2;
        number_1 = number_2;
        number_2 = number_3;
    }
    return total_sum;
}