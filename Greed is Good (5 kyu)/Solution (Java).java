public class Greed {
    public static int greedy(int[] dice) {
        int total_score = 0;
        for (int die_value = 1; die_value <= 6; die_value++) {
            int die_value_count = 0;
            for (int die : dice) {
                if (die == die_value) {
                    die_value_count++;
                }
            }
            if (die_value_count >= 3) {
                total_score += (die_value == 1) ? 1000 : die_value * 100;
                die_value_count -= 3;
            }
            if (die_value == 1) {
                total_score += die_value_count * 100;
            }
            if (die_value == 5) {
                total_score += die_value_count * 50;
            }
        }
        return total_score;
    }
}