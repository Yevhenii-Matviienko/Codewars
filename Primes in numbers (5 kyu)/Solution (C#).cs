public class PrimeDecomp {
    public static string factors(int lst) {
        string result = "";
        int divisor = 2;
        while (divisor * divisor <= lst) {
            int count_divisions = 0;
            while (lst % divisor == 0) {
                count_divisions++;
                lst /= divisor;
            }
            if (count_divisions == 1) {
                result += $"({divisor})";
            }
            else if (count_divisions > 1) {
                result += $"({divisor}**{count_divisions})";
            }
            divisor++;
        }
        if (lst > 1) {
            result += $"({lst})";
        }
        return result;
    }
}