def cut(cake):
    cake = cake.split('\n')
    cake_height, cake_width = len(cake), len(cake[0])
    cake_area = cake_height * cake_width
    count_raisins = sum(row.count('o') for row in cake)
    if cake_area % count_raisins != 0:
        return []
    piece_area = cake_area // count_raisins

    def get_count_raisins(row, column, height, width):
        return sum(
            cake[i][j] == 'o'
            for i in range(row, row + height)
            for j in range(column, column + width)
        )

    def make_piece(row, column, height, width):
        return '\n'.join(
            cake[i][column : column + width]
            for i in range(row, row + height)
        )

    pieces_shapes = []
    for height in range(1, cake_height + 1):
        if piece_area % height == 0:
            width = piece_area // height
            if width <= cake_width:
                pieces_shapes.append((height, width))
    pieces_shapes.sort(key=lambda x: -x[1])
    used_cake_part = [[False] * cake_width for _ in range(cake_height)]

    def get_first_free_cell():
        for row in range(cake_height):
            for column in range(cake_width):
                if not used_cake_part[row][column]:
                    return row, column
        return None

    def can_place_such_piece(row, column, height, width):
        if row + height > cake_height or column + width > cake_width:
            return False
        for i in range(row, row + height):
            for j in range(column, column + width):
                if used_cake_part[i][j]:
                    return False
        return get_count_raisins(row, column, height, width) == 1

    def place_such_piece(row, column, height, width, value):
        for i in range(row, row + height):
            for j in range(column, column + width):
                used_cake_part[i][j] = value

    def find_puzzle_solution(pieces):
        first_free_cell = get_first_free_cell()
        if first_free_cell is None:
            return pieces if len(pieces) == count_raisins else None
        row, column = first_free_cell
        for height, width in pieces_shapes:
            if can_place_such_piece(row, column, height, width):
                place_such_piece(row, column, height, width, True)
                result = find_puzzle_solution(pieces + [(row, column, height, width)])
                if result is not None:
                    return result
                place_such_piece(row, column, height, width, False)
        return None

    result = find_puzzle_solution([])
    if result is None:
        return []
    result.sort()
    return [
        make_piece(row, column, height, width)
        for row, column, height, width in result
    ]