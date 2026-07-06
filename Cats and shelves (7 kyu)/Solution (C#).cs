public class Kata {
    public static int Cats(int start, int finish) {
        int shelves_difference = finish - start;
        return shelves_difference / 3 + shelves_difference % 3;
    }
}