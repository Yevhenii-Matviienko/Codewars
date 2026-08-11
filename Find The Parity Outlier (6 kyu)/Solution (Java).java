public class FindOutlier {
    public static int find(int[] integers) {
        int even_numbers_count = 0;
        int odd_numbers_count = 0;
        int last_even_number = 0;
        int last_odd_number = 0;
        for (int integer : integers) {
            if (integer % 2 == 0) {
                even_numbers_count++;
                last_even_number = integer;
            } 
            else {
                odd_numbers_count++;
                last_odd_number = integer;
            }
        }
        return even_numbers_count == 1 ? last_even_number : last_odd_number;
    }
}