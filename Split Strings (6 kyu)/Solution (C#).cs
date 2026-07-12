public class SplitString {
    public static string[] Solution(string str) {
        int array_length = (str.Length + 1) / 2;
        string[] result = new string[array_length];
        for (int index = 0; index < str.Length; index += 2) {
            if (index + 1 < str.Length) {
                result[index / 2] = str.Substring(index, 2);
            }
            else {
                result[index / 2] = str.Substring(index, 1) + "_";
            }
        }
        return result;
    }
}