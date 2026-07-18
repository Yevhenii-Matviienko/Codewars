using System;

public class PyramidSlideDown {
    public static int LongestSlideDown(int[][] pyramid) {
        for (int row = pyramid.Length - 2; row >= 0; row--) {
            for (int column = 0; column < pyramid[row].Length; column++) {
                pyramid[row][column] += Math.Max(
                    pyramid[row + 1][column],
                    pyramid[row + 1][column + 1]
                );
            }
        }
        return pyramid[0][0];
    }
}