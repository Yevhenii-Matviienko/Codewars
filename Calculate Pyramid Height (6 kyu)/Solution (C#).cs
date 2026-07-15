public class Kata {
    public static int PyramidHeight(int n) {
        int height = 0;
        while (n >= (height + 1) * (height + 1)) {
            height++;
            n -= height * height;
        }
        return height;
    }
}