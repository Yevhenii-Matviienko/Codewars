class Sudoku(object):
    def __init__(self, data):
        self.data = data

    def is_valid(self):
        n = len(self.data)
        s = int(n ** 0.5)
        row_numbers = set(range(1, n + 1))
        return (
            s * s == n and
            all(len(row) == n for row in self.data) and
            all(set(row) == row_numbers for row in self.data) and
            all(set(row[i] for row in self.data) == row_numbers for i in range(n)) and
            all(
                set(self.data[i][j]
                    for i in range(row, row + s)
                    for j in range(column, column + s)) == row_numbers
                for row in range(0, n, s)
                for column in range(0, n, s)
            )
        )