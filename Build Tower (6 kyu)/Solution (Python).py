def tower_builder(n_floors):
    tower_width = 2 * n_floors - 1                
    return [("*" * (2 * floor - 1)).center(tower_width) for floor in range(1, n_floors + 1)]