using System;

public class Kata {
    public static bool Narcissistic(int value) {
        int sum = 0;
        string digits = value.ToString();
        int power = digits.Length;
        foreach (char digit in digits) {
            int number = digit - '0';
            sum += (int)Math.Pow(number, power);
        }
        return sum == value;
    }
}