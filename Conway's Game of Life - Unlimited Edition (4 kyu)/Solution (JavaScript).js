function getGeneration(cells, generations) {
  let live_cells = new Set();
  for (let y = 0; y < cells.length; y++) {
    for (let x = 0; x < cells[y].length; x++) {
      let cell = cells[y][x];
      if (cell === 1) {
        live_cells.add(`${y},${x}`);
      }
    }
  }
  const neighbours = [
    [-1, -1], [-1, 0], [-1, 1],
    [0, -1],           [0, 1],
    [1, -1],  [1, 0],  [1, 1]
  ];
  for (let index = 0; index < generations; index++) {
    let counts_live_neighbours = new Map();
    for (let cell_position of live_cells) {
      let [y, x] = cell_position.split(",").map(Number);
      for (let [dy, dx] of neighbours) {
        let neighbour_position = `${y + dy},${x + dx}`;
        counts_live_neighbours.set(
          neighbour_position,
          (counts_live_neighbours.get(neighbour_position) || 0) + 1
        );
      }
    }
    let next_live_cells = new Set();
    for (let [cell_position, live_neighbours] of counts_live_neighbours) {
      if (live_neighbours === 3 || (live_neighbours === 2 && live_cells.has(cell_position))) {
        next_live_cells.add(cell_position);
      }
    }
    live_cells = next_live_cells;
    if (live_cells.size === 0) {
      return [[]];
    }
  }
  if (live_cells.size === 0) {
    return [[]];
  }
  let ys = [...live_cells].map(cell_position => Number(cell_position.split(",")[0]));
  let xs = [...live_cells].map(cell_position => Number(cell_position.split(",")[1]));
  let min_y = Math.min(...ys);
  let max_y = Math.max(...ys);
  let min_x = Math.min(...xs);
  let max_x = Math.max(...xs);
  let result = [];
  for (let y = min_y; y <= max_y; y++) {
    let row = [];
    for (let x = min_x; x <= max_x; x++) {
      row.push(live_cells.has(`${y},${x}`) ? 1 : 0);
    }
    result.push(row);
  }
  return result;
}