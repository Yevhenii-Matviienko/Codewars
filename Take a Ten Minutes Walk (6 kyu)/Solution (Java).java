public class TenMinWalk {
    public static boolean isValid(char[] walk) {
        int n = 0, s = 0, e = 0, w = 0;
        for (char direction : walk) {
            if (direction == 'n') {
                n++;
            }
            if (direction == 's') { 
                s++;
            }
            if (direction == 'e') {
                e++;
            }
            if (direction == 'w') {
                w++;
            }
        }
        return walk.length == 10 && n == s && e == w;
    }
}