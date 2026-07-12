using System;
using System.Linq;

public class Kata {
    public static string PigIt(string str) {
        return string.Join(" ", str.Split(" ").Select(word =>
            word.All(char.IsLetter) ? word.Substring(1) + word[0] + "ay" : word)
        );
    }
}