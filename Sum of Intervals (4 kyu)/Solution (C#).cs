using System;
using System.Linq;

public class Intervals {
    public static int SumIntervals((int, int)[] intervals) {
        if (intervals.Length == 0) {
            return 0;
        }
        intervals = intervals.OrderBy(interval => interval.Item1).ToArray();
        int start = intervals[0].Item1;
        int end = intervals[0].Item2;
        int total_length = 0;
        for (int index = 1; index < intervals.Length; index++) {
            int current_start = intervals[index].Item1;
            int current_end = intervals[index].Item2;
            if (current_start <= end) {
                end = Math.Max(end, current_end);
            }
            else {
                total_length += end - start;
                start = current_start;
                end = current_end;
            }
        }
        return total_length + end - start;
    }
}