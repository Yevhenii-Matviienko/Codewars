using System.Linq;

public class Kata {
    public static int[] ArrayDiff(int[] a, int[] b) {
        return a.Where(element => !b.Contains(element)).ToArray();
    }
}
