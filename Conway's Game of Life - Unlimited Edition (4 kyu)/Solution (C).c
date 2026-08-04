#include <stdlib.h>

int **get_generation(const int *const cells[], int generations, int *rowptr, int *colptr) {
    int rows = *rowptr;
    int columns = *colptr;
    int **rows_pointers = malloc(rows * sizeof(int *));
    for (int y = 0; y < rows; y++) {
        rows_pointers[y] = malloc(columns * sizeof(int));
        for (int x = 0; x < columns; x++) {
            rows_pointers[y][x] = cells[y][x];
        }
    }
    for (int generation = 0; generation < generations; generation++) {
        int new_rows = rows + 2;
        int new_columns = columns + 2;
        int **expanded_rows_pointers = malloc(new_rows * sizeof(int *));
        int **next_generation_rows_pointers = malloc(new_rows * sizeof(int *));
        for (int y = 0; y < new_rows; y++) {
            expanded_rows_pointers[y] = calloc(new_columns, sizeof(int));
            next_generation_rows_pointers[y] = calloc(new_columns, sizeof(int));
        }
        for (int y = 0; y < rows; y++) {
            for (int x = 0; x < columns; x++) {
                expanded_rows_pointers[y + 1][x + 1] = rows_pointers[y][x];
            }
            free(rows_pointers[y]);
        }
        free(rows_pointers);
        for (int y = 0; y < new_rows; y++) {
            for (int x = 0; x < new_columns; x++) {
                int number_live_neighbours = 0;
                for (int dy = -1; dy <= 1; dy++) {
                    for (int dx = -1; dx <= 1; dx++) {
                        int neighbour_y = y + dy;
                        int neighbour_x = x + dx;
                        if (dy == 0 && dx == 0) {
                            continue;
                        }
                        if (neighbour_y >= 0 && neighbour_y < new_rows && neighbour_x >= 0 && neighbour_x < new_columns) {
                            number_live_neighbours += expanded_rows_pointers[neighbour_y][neighbour_x];
                        }
                    }
                }
                if (number_live_neighbours == 3 || (expanded_rows_pointers[y][x] == 1 && number_live_neighbours == 2)) {
                    next_generation_rows_pointers[y][x] = 1;
                }
            }
        }
        for (int y = 0; y < new_rows; y++) {
            free(expanded_rows_pointers[y]);
        }
        free(expanded_rows_pointers);
        rows_pointers = next_generation_rows_pointers;
        rows = new_rows;
        columns = new_columns;
    }
    int min_y = rows;
    int max_y = -1;
    int min_x = columns;
    int max_x = -1;
    for (int y = 0; y < rows; y++) {
        for (int x = 0; x < columns; x++) {
            if (rows_pointers[y][x] == 1) {
                if (y < min_y) {
                    min_y = y;
                }
                if (y > max_y) {
                    max_y = y;
                }
                if (x < min_x) {
                    min_x = x;
                }
                if (x > max_x) {
                    max_x = x;
                }
            }
        }
    }
    if (max_y == -1) {
        for (int y = 0; y < rows; y++) {
            free(rows_pointers[y]);
        }
        free(rows_pointers);
        int **result = malloc(sizeof(int *));
        result[0] = NULL;
        *rowptr = 1;
        *colptr = 0;
        return result;
    }
    int result_rows = max_y - min_y + 1;
    int result_cols = max_x - min_x + 1;
    int **result = malloc(result_rows * sizeof(int *));
    for (int y = 0; y < result_rows; y++) {
        result[y] = malloc(result_cols * sizeof(int));
        for (int x = 0; x < result_cols; x++) {
            result[y][x] = rows_pointers[min_y + y][min_x + x];
        }
    }
    for (int y = 0; y < rows; y++) {
        free(rows_pointers[y]);
    }
    free(rows_pointers);
    *rowptr = result_rows;
    *colptr = result_cols;
    return result;
}