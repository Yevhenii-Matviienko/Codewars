using System.Collections.Generic;
using System.Linq;

public class ConwayLife {
    public static int[,] GetGeneration(int[,] cells, int generations) {
        HashSet<(int y, int x)> live_cells = new HashSet<(int y, int x)>();
        int rows = cells.GetLength(0);
        int columns = cells.GetLength(1);
        for (int y = 0; y < rows; y++) {
            for (int x = 0; x < columns; x++) {
                if (cells[y, x] == 1) {
                    live_cells.Add((y, x));
                }
            }
        }
        int[,] neighbours = {
            {-1, -1}, {-1, 0}, {-1, 1},
            {0, -1},           {0, 1},
            {1, -1},  {1, 0},  {1, 1}
        };
        for (int generation = 0; generation < generations; generation++) {
            Dictionary<(int y, int x), int> counts_live_neighbours = new Dictionary<(int y, int x), int>();
            foreach ((int y, int x) live_cell in live_cells) {
                for (int direction = 0; direction < 8; direction++) {
                    int neighbour_y = live_cell.y + neighbours[direction, 0];
                    int neighbour_x = live_cell.x + neighbours[direction, 1];
                    var neighbour_position = (neighbour_y, neighbour_x);
                    if (counts_live_neighbours.ContainsKey(neighbour_position)) {
                        counts_live_neighbours[neighbour_position]++;
                    }
                    else {
                        counts_live_neighbours[neighbour_position] = 1;
                    }
                }
            }
            HashSet<(int y, int x)> next_generation_live_cells = new HashSet<(int y, int x)>();
            foreach (var item in counts_live_neighbours) {
                var position = item.Key;
                int number_live_neighbours = item.Value;
                if (number_live_neighbours == 3 || (number_live_neighbours == 2 && live_cells.Contains(position))) {
                    next_generation_live_cells.Add(position);
                }
            }
            live_cells = next_generation_live_cells;
            if (live_cells.Count == 0) {
                return new int[1, 0];
            }
        }
        if (live_cells.Count == 0) {
            return new int[1, 0];
        }
        int min_y = live_cells.Min(live_cell => live_cell.y);
        int max_y = live_cells.Max(live_cell => live_cell.y);
        int min_x = live_cells.Min(live_cell => live_cell.x);
        int max_x = live_cells.Max(live_cell => live_cell.x);
        int result_rows = max_y - min_y + 1;
        int result_columns = max_x - min_x + 1;
        int[,] result = new int[result_rows, result_columns];
        foreach ((int y, int x) live_cell in live_cells) {
            result[live_cell.y - min_y, live_cell.x - min_x] = 1;
        }
        return result;
    }
}