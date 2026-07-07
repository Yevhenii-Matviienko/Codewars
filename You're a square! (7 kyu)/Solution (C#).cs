using System;

public class Kata {
    public static bool IsSquare(int n) {
        return n >= 0 && Math.Sqrt(n) % 1 == 0;
    }
}