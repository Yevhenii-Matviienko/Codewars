public static class Kata {
    public static long Fibonacci(int max) {
        long number_1 = 0;
        long number_2 = 1;
        long total_sum = 0;
        while (number_1 < max) {
            if (number_1 % 2 == 0) {
                total_sum += number_1;
            }
            long number_3 = number_1 + number_2;
            number_1 = number_2;
            number_2 = number_3;
        }
        return total_sum;
    }
}