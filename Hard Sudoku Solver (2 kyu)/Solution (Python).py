def sudoku_solver(puzzle):
    def number_to_bits_mask(number):
        return 1 << (number - 1)

    def get_box_3_x_3_index(row, column):
        return (row // 3) * 3 + (column // 3)

    if (
        not isinstance(puzzle, list)
        or len(puzzle) != 9
        or any(not isinstance(row, list) or len(row) != 9 for row in puzzle)
    ):
        raise ValueError('Invalid sudoku grid')
    numbers_bits_mask = (1 << 9) - 1
    sudoku_grid = [row[:] for row in puzzle]
    rows = [0] * 9
    columns = [0] * 9
    boxes_3_x_3 = [0] * 9
    empty_cells = []
    for row in range(9):
        for column in range(9):
            value = sudoku_grid[row][column]
            if not isinstance(value, int) or value < 0 or value > 9:
                raise ValueError('Invalid sudoku grid values')
            if value == 0:
                empty_cells.append((row, column))
            else:
                value_bits_mask = number_to_bits_mask(value)
                box_3_x_3_index = get_box_3_x_3_index(row, column)
                if rows[row] & value_bits_mask or columns[column] & value_bits_mask or boxes_3_x_3[box_3_x_3_index] & value_bits_mask:
                    raise ValueError('Sudoku grid value duplication')
                rows[row] |= value_bits_mask
                columns[column] |= value_bits_mask
                boxes_3_x_3[box_3_x_3_index] |= value_bits_mask
    solutions = []

    def numbers_candidates(row, column):
        used_numbers_bits_mask = rows[row] | columns[column] | boxes_3_x_3[get_box_3_x_3_index(row, column)]
        return numbers_bits_mask & ~used_numbers_bits_mask

    def find_puzzle_solution():
        if len(solutions) > 1:
            return
        best_empty_cell_index = -1
        best_numbers_bits_mask = 0
        best_count_numbers_candidates = 10
        for index, (row, column) in enumerate(empty_cells):
            if sudoku_grid[row][column] == 0:
                numbers_candidates_bits_mask = numbers_candidates(row, column)
                count_free_numbers = numbers_candidates_bits_mask.bit_count()
                if count_free_numbers == 0:
                    return
                if count_free_numbers < best_count_numbers_candidates:
                    best_count_numbers_candidates = count_free_numbers
                    best_empty_cell_index = index
                    best_numbers_bits_mask = numbers_candidates_bits_mask
                    if count_free_numbers == 1:
                        break
        if best_empty_cell_index == -1:
            solutions.append([row[:] for row in sudoku_grid])
            return
        row, column = empty_cells[best_empty_cell_index]
        box_3_x_3 = get_box_3_x_3_index(row, column)
        mask = best_numbers_bits_mask
        while mask:
            least_bit = mask & -mask
            value = least_bit.bit_length()
            sudoku_grid[row][column] = value
            rows[row] |= least_bit
            columns[column] |= least_bit
            boxes_3_x_3[box_3_x_3] |= least_bit
            find_puzzle_solution()
            rows[row] ^= least_bit
            columns[column] ^= least_bit
            boxes_3_x_3[box_3_x_3] ^= least_bit
            sudoku_grid[row][column] = 0
            if len(solutions) > 1:
                return
            mask -= least_bit

    find_puzzle_solution()
    if len(solutions) != 1:
        raise ValueError('Sudoku must have exactly one solution')
    return solutions[0]