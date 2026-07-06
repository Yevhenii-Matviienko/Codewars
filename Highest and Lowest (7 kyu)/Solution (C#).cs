using System.Linq;

public static class Kata {
    public static string HighAndLow(string numbers) {
        int[] numbers_int_array = numbers.Split(' ').Select(int.Parse).ToArray();
        return $"{numbers_int_array.Max()} {numbers_int_array.Min()}";
    }
}