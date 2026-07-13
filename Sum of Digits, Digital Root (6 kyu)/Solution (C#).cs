public class Number {
    public static int DigitalRoot(long n) {
        return n == 0 ? 0 : (int)(n % 9 == 0 ? 9 : n % 9);
    }
}