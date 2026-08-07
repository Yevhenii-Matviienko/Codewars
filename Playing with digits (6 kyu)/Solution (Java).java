public class DigPow {
    public static long digPow(int n, int p) {
        long sum = 0;
        for (char digit : String.valueOf(n).toCharArray()) {
            sum += (long) Math.pow(digit - '0', p);
            p++;
        }
        return sum % n == 0 ? sum / n : -1;
    }
}