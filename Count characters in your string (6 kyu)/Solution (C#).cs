using System.Collections.Generic;

public class Kata {
    public static Dictionary<char, int> Count(string str) {
        Dictionary<char, int> result = new Dictionary<char, int>();
        foreach (char character in str) {
            if (result.ContainsKey(character)) {
                result[character]++;
            }
            else {
                result[character] = 1;
            }
        }
        return result;
    }
}