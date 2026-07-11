using System.Linq;

public class Kata {
    public static string DuplicateEncode(string word) {
        word = word.ToLower();
        return string.Concat(word.Select(letter => word.Count(character => character == letter) > 1 ? ")" : "("));
    }
}