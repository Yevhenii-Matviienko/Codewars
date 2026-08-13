package cw;

public class Interval {
    public static int sumIntervals(int[][] intervals) {
        if (intervals.length == 0) {
            return 0;
        }
        for (int index_1 = 0; index_1 < intervals.length - 1; index_1++) {
            for (int index_2 = index_1 + 1; index_2 < intervals.length; index_2++) {
                if (intervals[index_1][0] > intervals[index_2][0]) {
                    int[] temporary = intervals[index_1];
                    intervals[index_1] = intervals[index_2];
                    intervals[index_2] = temporary;
                }
            }
        }
        int current_interval_start = intervals[0][0];
        int current_interval_end = intervals[0][1];
        int total_length = 0;
        for (int index_1 = 1; index_1 < intervals.length; index_1++) {
            int next_interval_start = intervals[index_1][0];
            int next_interval_end = intervals[index_1][1];
            if (next_interval_start <= current_interval_end) {
                if (next_interval_end > current_interval_end) {
                    current_interval_end = next_interval_end;
                }
            } 
            else {
                total_length += current_interval_end - current_interval_start;
                current_interval_start = next_interval_start;
                current_interval_end = next_interval_end;
            }
        }
        total_length += current_interval_end - current_interval_start;
        return total_length;
    }
}