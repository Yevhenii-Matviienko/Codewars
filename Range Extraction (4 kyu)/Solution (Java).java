public class Solution {
    public static String rangeExtraction(int[] arr) {
        StringBuilder result = new StringBuilder();
        for (int index = 0; index < arr.length; index++) {
            int range_start = index;
            while (index + 1 < arr.length && arr[index + 1] == arr[index] + 1) {
                index++;
            } 
            if (result.length() > 0) {
                result.append(",");
            }
            result.append(arr[range_start]);
            if (index - range_start >= 2) {
                result.append("-").append(arr[index]);
            }
            else if (index - range_start == 1) {
                result.append(",").append(arr[index]);
            }  
        }
        return result.toString();
    }
}