using System;

public class DigPow {
    public static long digPow(int n, int p) {
        long sum = 0;
        foreach (char digit in n.ToString()) {
            sum += (long)Math.Pow(digit - '0', p);
            p++;
        }
        return sum % n == 0 ? sum / n : -1;
    }
}
