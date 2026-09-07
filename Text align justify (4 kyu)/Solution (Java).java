import java.util.*;

public class Kata {
    public static String justify(String text, int width) {
        if (text.isBlank()) {
            return "";
        }
        String[] words = text.trim().split("\\s+");
        List<String> line = new ArrayList<>();
        int line_words_length = 0;
        List<String> result = new ArrayList<>();
        for (String word : words) {
            if (line_words_length + line.size() + word.length() > width) {
                result.add(format(line, width));
                line.clear();
                line_words_length = 0;
            }
            line.add(word);
            line_words_length += word.length();
        }
        result.add(String.join(" ", line));
        return String.join("\n", result);
    }

    private static String format(List<String> line, int width) {
        if (line.size() == 1) {
            return line.get(0);
        }
        int symbols = 0;
        for (String word : line) {
            symbols += word.length();
        }
        int gaps = line.size() - 1;
        int spaces = width - symbols;
        StringBuilder result = new StringBuilder();
        for (int index = 0; index < line.size(); index++) {
            result.append(line.get(index));
            if (index < gaps) {
                int count_spaces = spaces / gaps;
                if (index < spaces % gaps) {
                    count_spaces++;
                }
                result.append(" ".repeat(count_spaces));
            }
        }
        return result.toString();
    }
}