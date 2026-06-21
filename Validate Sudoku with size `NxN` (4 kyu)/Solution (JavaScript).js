var Sudoku = function(data) {
  return { isValid: function() {
    const n = data.length;
    const s = Math.sqrt(n);
    if (!Number.isInteger(s)) return false;
    if (!data.every(row => row.length === n)) return false;
    const row_numbers = new Set(
      Array.from({length: n}, (_, index) => index + 1)
    );
    
    const is_valid_numbers_group = numbers_group => {
      if (numbers_group.length !== n) return false;
      const numbers_group_set = new Set(numbers_group);
      if (numbers_group_set.size !== n) return false;
      for (const number of row_numbers) {
        if (!numbers_group_set.has(number)) return false;
      }
      return true;
    };
    
    for (let row = 0; row < n; row++) {
      if (!is_valid_numbers_group(data[row])) return false;
    }
    for (let column = 0; column < n; column++) {
      const column_numbers = [];
      for (let row = 0; row < n; row++) {
        column_numbers.push(data[row][column]);
      }
      if (!is_valid_numbers_group(column_numbers)) return false;
    }
    for (let row = 0; row < n; row += s) {
      for (let column = 0; column < n; column += s) {
        const numbers_square = [];
        for (let i = row; i < row + s; i++) {
          for (let j = column; j < column + s; j++) {
            numbers_square.push(data[i][j]);
          }
        }
        if (!is_valid_numbers_group(numbers_square)) return false;
      }
    }
    return true;
  }};
};