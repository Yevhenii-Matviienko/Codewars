public class ProdFib {
    public static long[] productFib(long prod) {
        long number_1 = 0;
        long number_2 = 1;
        while (number_1 * number_2 < prod) {
            long number_3 = number_1 + number_2;
            number_1 = number_2;
            number_2 = number_3;
        }
        return new long[] {number_1, number_2, number_1 * number_2 == prod ? 1 : 0};
    }
}