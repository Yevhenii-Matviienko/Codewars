from preloaded import htmlize

def get_generation(cells: list[list[int]], generations: int) -> list[list[int]]:
    live_cells = {
        (y, x)
        for y, row in enumerate(cells)
        for x, cell in enumerate(row)
        if cell == 1
    }
    neighbours = [
        (-1, -1), (-1, 0), (-1, 1),
        (0, -1),           (0, 1),
        (1, -1),  (1, 0),  (1, 1)
    ]
    for _ in range(generations):
        counts_live_neighbours = {}
        for y, x in live_cells:
            for dy, dx in neighbours:
                neighbour_position = (y + dy, x + dx)
                counts_live_neighbours[neighbour_position] = counts_live_neighbours.get(neighbour_position, 0) + 1
        live_cells = {
            cell_position
            for cell_position, live_neighbours in counts_live_neighbours.items()
            if live_neighbours == 3 or (live_neighbours == 2 and cell_position in live_cells)
        }
        if not live_cells:
            return [[]]
    if not live_cells:
        return [[]]
    min_y = min(y for y, x in live_cells)
    max_y = max(y for y, x in live_cells)
    min_x = min(x for y, x in live_cells)
    max_x = max(x for y, x in live_cells)
    return [
        [
            1 if (y, x) in live_cells else 0
            for x in range(min_x, max_x + 1)
        ]
        for y in range(min_y, max_y + 1)
    ]