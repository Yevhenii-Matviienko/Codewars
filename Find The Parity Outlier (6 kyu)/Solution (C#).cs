using System.Linq;

public class Kata {
    public static int Find(int[] integers) {
        var evens_integers = integers.Where(integer => integer % 2 == 0).ToArray();
        var odds_integers = integers.Where(integer => integer % 2 != 0).ToArray();
        return evens_integers.Length == 1 ? evens_integers[0] : odds_integers[0];
    }
}