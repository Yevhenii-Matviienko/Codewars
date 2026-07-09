public class ProdFib {
    public static ulong[] productFib(ulong prod) {
        ulong number_1 = 0;
        ulong number_2 = 1;
        while (number_1 * number_2 < prod) {
            ulong number_3 = number_1 + number_2;
            number_1 = number_2;
            number_2 = number_3;
        }
        return new ulong[] { 
            number_1, 
            number_2, 
            number_1 * number_2 == prod ? 1UL : 0UL 
        };
    }
}