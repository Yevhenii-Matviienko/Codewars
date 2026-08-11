import java.util.Map;
import java.util.HashMap;

public class Kata {
    public static Map<Character, Integer> count(String str) {
        Map<Character, Integer> result = new HashMap<>();
        for (char symbol : str.toCharArray()) {
            if (result.containsKey(symbol)) {
                result.put(symbol, result.get(symbol) + 1);
            } 
            else {
                result.put(symbol, 1);
            }
        }
        return result;
    }
}