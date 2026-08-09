public class DuplicateEncoder {
    static String encode(String word) {
        word = word.toLowerCase();
        StringBuilder result = new StringBuilder();
        for (char symbol : word.toCharArray()) {
            if (word.indexOf(symbol) != word.lastIndexOf(symbol)) {
                result.append(')');
            } 
            else {
                result.append('(');
            }
        }
        return result.toString();
    }
}