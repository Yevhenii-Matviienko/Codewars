import java.util.*;

public class SmileFaces {
    public static int countSmileys(List<String> arr) {
        int smileys_counter = 0;
        for (String smiley : arr) {
            if (smiley.matches("[:;][-~]?[)D]")) {
                smileys_counter++;
            }
        }
        return smileys_counter;
    }
}
