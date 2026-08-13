public class StripComments {
    public static String stripComments(String text, String[] commentSymbols) {
        String[] lines = text.split("\n", -1);
        StringBuilder result = new StringBuilder();
        for (int line_index = 0; line_index < lines.length; line_index++) {
            String line = lines[line_index];
            int comment_index = line.length();
            for (String comment_symbol : commentSymbols) {
                int comment_symbol_index = line.indexOf(comment_symbol);
                if (comment_symbol_index != -1 && comment_symbol_index < comment_index) {
                    comment_index = comment_symbol_index;
                }
            }
            line = line.substring(0, comment_index).stripTrailing();
            result.append(line);
            if (line_index < lines.length - 1) {
                result.append("\n");
            }
        }
        return result.toString();
    }
}