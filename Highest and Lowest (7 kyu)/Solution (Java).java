import java.util.Arrays;

public class Kata {
    public static String highAndLow(String numbers) {
        int[] numbers_array = Arrays.stream(numbers.split(" ")).mapToInt(Integer::parseInt).toArray();
        int max_number = Arrays.stream(numbers_array).max().getAsInt();
        int min_number = Arrays.stream(numbers_array).min().getAsInt();
        return max_number + " " + min_number;
    }
}