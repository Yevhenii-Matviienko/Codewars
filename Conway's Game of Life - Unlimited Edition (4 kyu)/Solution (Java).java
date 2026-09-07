public class ConwayLife {
    public static int[][] getGeneration(int[][] cells, int generations) {
        int rows = cells.length;
        int columns = cells[0].length;
        int[][] field = new int[rows + generations * 2][columns + generations * 2];
        for (int row = 0; row < rows; row++) {
            for (int column = 0; column < columns; column++) {
                field[row + generations][column + generations] = cells[row][column];
            }
        }
        for (int generation = 0; generation < generations; generation++) {
            int[][] next_field = new int[field.length][field[0].length];
            for (int row = 0; row < field.length; row++) {
                for (int column = 0; column < field[0].length; column++) {
                    int neighbours = 0;
                    for (int d_row = -1; d_row <= 1; d_row++) {
                        for (int d_column = -1; d_column <= 1; d_column++) {
                            if ((d_column != 0 || d_row != 0) && row + d_row >= 0 && row + d_row < field.length && column + d_column >= 0 && column + d_column < field[0].length) {
                                neighbours += field[row + d_row][column + d_column];
                            }
                        }
                    }
                    if (neighbours == 3 || (field[row][column] == 1 && neighbours == 2)) {
                        next_field[row][column] = 1;
                    }
                }
            }
            field = next_field;
        }
        return crop_field(field);
    }

    private static int[][] crop_field(int[][] field) {
        int top_limit = field.length;
        int bottom_limit = -1;
        int left_limit = field.length == 0 ? 0 : field[0].length;
        int right_limit = -1;
        for (int row = 0; row < field.length; row++) {
            for (int column = 0; column < field[row].length; column++) {
                if (field[row][column] == 1) {
                    top_limit = Math.min(top_limit, row);
                    bottom_limit = Math.max(bottom_limit, row);
                    left_limit = Math.min(left_limit, column);
                    right_limit = Math.max(right_limit, column);
                }
            }
        }
        if (bottom_limit == -1) {
            return new int[][]{{}};
        }
        int[][] result = new int[bottom_limit - top_limit + 1][right_limit - left_limit + 1];
        for (int row = top_limit; row <= bottom_limit; row++) {
            for (int column = left_limit; column <= right_limit; column++) {
                result[row - top_limit][column - left_limit] = field[row][column];
            }
        }
        return result;
    }
}