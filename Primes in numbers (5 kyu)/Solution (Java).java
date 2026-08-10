public class PrimeDecomp {
    public static String factors(int n) {
        String result = "";
        int divisor = 2;
        while (divisor * divisor <= n) {
            int count_divisions = 0;
            while (n % divisor == 0) {
                count_divisions++;
                n /= divisor;
            }
            if (count_divisions == 1) {
                result += "(" + divisor + ")";
            } 
            else if (count_divisions > 1) {
                result += "(" + divisor + "**" + count_divisions + ")";
            }
            divisor++;
        }
        if (n > 1) {
            result += "(" + n + ")";
        }
        return result;
    }
}