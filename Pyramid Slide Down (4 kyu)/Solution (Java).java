public class LongestSlideDown {
    public static int longestSlideDown(int[][] pyramid) {
        for (int row = pyramid.length - 2; row >= 0; row--) {
            for (int column = 0; column < pyramid[row].length; column++) {
                pyramid[row][column] += Math.max(
                    pyramid[row + 1][column],
                    pyramid[row + 1][column + 1]
                );
            }
        }
        return pyramid[0][0];
    }
}