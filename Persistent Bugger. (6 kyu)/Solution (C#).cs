public class Persist {
    public static int Persistence(long n) {
        int count_multiplications = 0;
        while (n >= 10) {
            long product = 1;
            foreach (char digit in n.ToString()) {
                product *= digit - '0';
            }  
            n = product;
            count_multiplications++;
        }
        return count_multiplications;
    }
}