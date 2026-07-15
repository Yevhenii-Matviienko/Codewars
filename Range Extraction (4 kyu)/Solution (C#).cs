using System.Collections.Generic;

public class RangeExtraction {
    public static string Extract(int[] args) {
        List<string> result = new List<string>();
        int index = 0;
        while (index < args.Length) {
            int start = args[index];
            while (index + 1 < args.Length && args[index + 1] == args[index] + 1) {
                index++;
            }
            int end = args[index];
            if (end - start >= 2) {
                result.Add(start + "-" + end);
            }
            else if (end - start == 1) {
                result.Add(start.ToString());
                result.Add(end.ToString());
            }
            else {
                result.Add(start.ToString());
            }
            index++;
        }
        return string.Join(",", result);
    }
}