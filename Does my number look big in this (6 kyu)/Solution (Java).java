public class NumberUtils {
    public static boolean isNarcissistic(int number) {
        int sum = 0;
        String digits = String.valueOf(number);
        for (char digit : digits.toCharArray()) {
            sum += Math.pow(digit - '0', digits.length());
        }
        return sum == number;
    }
}