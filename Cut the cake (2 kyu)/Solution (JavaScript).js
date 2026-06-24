function cut(cake) {
  cake = cake.split('\n');
  const cake_height = cake.length;
  const cake_width = cake[0].length;
  const cake_area = cake_height * cake_width;
  const count_raisins = cake.reduce((sum, row) => {
    return sum + row.split('').filter(char => char === 'o').length;
  }, 0);
  if (cake_area % count_raisins !== 0) {
    return [];
  }
  const piece_area = cake_area / count_raisins;

  function get_count_raisins(row, column, height, width) {
    let count = 0;
    for (let i = row; i < row + height; i++) {
      for (let j = column; j < column + width; j++) {
        if (cake[i][j] === 'o') {
          count++;
        }
      }
    }
    return count;
  }

  function make_piece(row, column, height, width) {
    const piece = [];
    for (let i = row; i < row + height; i++) {
      piece.push(cake[i].slice(column, column + width));
    }
    return piece.join('\n');
  }

  const pieces_shapes = [];
  for (let height = 1; height <= cake_height; height++) {
    if (piece_area % height === 0) {
      const width = piece_area / height;
      if (width <= cake_width) {
        pieces_shapes.push([height, width]);
      }
    }
  }
  pieces_shapes.sort((a, b) => b[1] - a[1]);
  const used_cake_part = Array.from({ length: cake_height }, () => {
    return Array(cake_width).fill(false);
  });

  function get_first_free_cell() {
    for (let row = 0; row < cake_height; row++) {
      for (let column = 0; column < cake_width; column++) {
        if (!used_cake_part[row][column]) {
          return [row, column];
        }
      }
    }
    return null;
  }

  function can_place_such_piece(row, column, height, width) {
    if (row + height > cake_height || column + width > cake_width) {
      return false;
    }
    for (let i = row; i < row + height; i++) {
      for (let j = column; j < column + width; j++) {
        if (used_cake_part[i][j]) {
          return false;
        }
      }
    }
    return get_count_raisins(row, column, height, width) === 1;
  }

  function place_such_piece(row, column, height, width, value) {
    for (let i = row; i < row + height; i++) {
      for (let j = column; j < column + width; j++) {
        used_cake_part[i][j] = value;
      }
    }
  }

  function find_puzzle_solution(pieces) {
    const first_free_cell = get_first_free_cell();
    if (first_free_cell === null) {
      if (pieces.length === count_raisins) {
        return pieces;
      }
      return null;
    }
    const [row, column] = first_free_cell;
    for (const [height, width] of pieces_shapes) {
      if (can_place_such_piece(row, column, height, width)) {
        place_such_piece(row, column, height, width, true);
        const result = find_puzzle_solution([...pieces, [row, column, height, width]]);
        if (result !== null) {
          return result;
        }
        place_such_piece(row, column, height, width, false);
      }
    }
    return null;
  }

  const result = find_puzzle_solution([]);
  if (result === null) {
    return [];
  }
  result.sort((a, b) => {
    if (a[0] !== b[0]) {
      return a[0] - b[0];
    }
    return a[1] - b[1];
  });
  return result.map(([row, column, height, width]) => {
    return make_piece(row, column, height, width);
  });
}