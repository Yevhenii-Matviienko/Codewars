public class Square {
    public static boolean isSquare(int n) {
        if (n < 0) {
            return false;
        }
        int square_root = (int) Math.sqrt(n);
        return square_root * square_root == n;
    }
}