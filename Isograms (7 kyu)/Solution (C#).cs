using System.Linq;

public class Kata {
    public static bool IsIsogram(string str) {
        string string_lowercase = str.ToLower();
        return string_lowercase.Distinct().Count() == string_lowercase.Length;
    }
}