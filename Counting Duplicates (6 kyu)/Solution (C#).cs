using System.Linq;

public class Kata {
    public static int DuplicateCount(string str) {
        return str.ToLower().GroupBy(symbol => symbol).Count(symbol_group => symbol_group.Count() > 1);
    }
}