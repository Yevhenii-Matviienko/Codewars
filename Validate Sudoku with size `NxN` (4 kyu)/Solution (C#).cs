using System;
using System.Collections.Generic;

class Sudoku {
    private readonly int[][] sudoku_table;

    public Sudoku(int[][] sudoku_data) {
        sudoku_table = sudoku_data;
    }

    private bool check_group_validation(int[] values, int n) {
        var numbers = new HashSet<int>();
        foreach (int value in values) {
            if (value < 1 || value > n) {
                return false;
            }
            if (!numbers.Add(value)) {
                return false;
            } 
        }
        return numbers.Count == n;
    }

    public bool IsValid() {
        if (sudoku_table == null || sudoku_table.Length == 0) {
            return false;
        }
        int n = sudoku_table.Length;
        int s = (int)Math.Sqrt(n);
        if (s * s != n) {
            return false;
        }
        foreach (int[] row in sudoku_table) {
            if (row == null || row.Length != n) {
                return false;
            }
        }
        for (int row = 0; row < n; row++) {
            if (!check_group_validation(sudoku_table[row], n)) {
                return false;
            }
        }
        for (int column = 0; column < n; column++) {
            int[] column_numbers = new int[n];
            for (int row = 0; row < n; row++) {
                column_numbers[row] = sudoku_table[row][column];
            }
            if (!check_group_validation(column_numbers, n)) {
                return false;
            }
        }
        for (int start_row = 0; start_row < n; start_row += s) {
            for (int start_column = 0; start_column < n; start_column += s) {
                int[] square_values = new int[n];
                int index = 0;
                for (int row = start_row; row < start_row + s; row++) {
                    for (int column = start_column; column < start_column + s; column++) {
                        square_values[index++] = sudoku_table[row][column];
                    }
                }
                if (!check_group_validation(square_values, n)) {
                    return false;
                }
            }
        }
        return true;
    }
}