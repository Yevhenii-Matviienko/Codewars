using System;
using System.Linq;

public static class Kata {
    public static int DescendingOrder(int num) {
        string result = string.Concat(num.ToString().OrderByDescending(digit => digit));
        return int.Parse(result);
    }
}