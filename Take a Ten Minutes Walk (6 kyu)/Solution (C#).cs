using System.Linq;

public class Kata {
    public static bool IsValidWalk(string[] walk) {
        return walk.Length == 10 &&
            walk.Count(direction => direction == "n") == walk.Count(direction => direction == "s") &&
            walk.Count(direction => direction == "e") == walk.Count(direction => direction == "w");
    }
}