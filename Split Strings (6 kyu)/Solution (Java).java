public class StringSplit {
    public static String[] solution(String s) {
        if (s.length() % 2 != 0) {
            s += "_";
        }
        String[] result = new String[s.length() / 2];
        for (int index = 0; index < s.length(); index += 2) {
            result[index / 2] = s.substring(index, index + 2);
        }
        return result;
    }
}