using System.Linq;

public class StripCommentsSolution {
    public static string StripComments(string text, string[] commentSymbols) =>
        string.Join("\n", text.Split("\n").Select(line =>
        commentSymbols.Aggregate(line, (processed_line, comment_symbol) => 
        processed_line.Split(comment_symbol)[0]).TrimEnd()));
}