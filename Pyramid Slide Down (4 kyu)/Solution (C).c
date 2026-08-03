int pyramid_slide_down(int num_elements, const int pyramid[num_elements], int rows) {
    int max_sums_paths_elements[num_elements];
    for (int index = 0; index < num_elements; index++) {
        max_sums_paths_elements[index] = pyramid[index];
    }
    for (int row = rows - 2; row >= 0; row--) {
        int current_row_first_element_index = row * (row + 1) / 2;
        int next_row_first_element_index = (row + 1) * (row + 2) / 2;
        for (int column = 0; column <= row; column++) {
            int next_row_left_element = max_sums_paths_elements[next_row_first_element_index + column];
            int next_row_right_element = max_sums_paths_elements[next_row_first_element_index + column + 1];
            max_sums_paths_elements[current_row_first_element_index + column] += next_row_left_element > next_row_right_element ? next_row_left_element : next_row_right_element;
        }
    }
    return max_sums_paths_elements[0];
}