using System.Collections.Generic;

public class DirReduction {
    public static string[] dirReduc(string[] arr) {
        Dictionary<string, string> opposites_directions = new Dictionary<string, string> {
            { "NORTH", "SOUTH" },
            { "SOUTH", "NORTH" },
            { "EAST", "WEST" },
            { "WEST", "EAST" }
        };
        List<string> result = new List<string>();
        foreach (string direction in arr) {
            if (result.Count > 0 && opposites_directions[direction] == result[result.Count - 1]) {
                result.RemoveAt(result.Count - 1);
            }
            else {
                result.Add(direction);
            }
        }
        return result.ToArray();
    }
}