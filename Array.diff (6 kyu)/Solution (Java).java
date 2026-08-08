import java.util.Arrays;
import java.util.Set;
import java.util.HashSet;

public class Kata {
    public static int[] arrayDiff(int[] a, int[] b) {
        Set<Integer> array_2_set = new HashSet<>();
        for (int element : b) {
            array_2_set.add(element);
        }
        return Arrays.stream(a).filter(element -> !array_2_set.contains(element)).toArray();
    }
}