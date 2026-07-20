typedef unsigned long long ull;

ull even_fib(ull limit) {
    ull number_1 = 0;
    ull number_2 = 1;
    ull total_sum = 0;
    while (number_1 < limit) {
        if (number_1 % 2 == 0) {
            total_sum += number_1;
        }
        ull number_3 = number_1 + number_2;
        number_1 = number_2;
        number_2 = number_3;
    }
    return total_sum;
}