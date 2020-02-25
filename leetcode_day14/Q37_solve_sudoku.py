class Solution:
    def __init__(self):
        self.squares = []
        self.col = []
        self.row = []
        self.board = None

    # 尝试填充第row行
    def fill(self, row, col, record):
        if row == 9:
            return True

        if self.board[row][col] == ".":
            for num in range(1, 10):
                if num not in self.col[col] and num not in self.row[row] and num not in self.squares[(row//3)*3 + col//3]:
                    record.append(num)
                    self.col[col].add(num)
                    self.row[row].add(num)
                    self.squares[(row//3)*3 + col//3].add(num)
                    new_row, new_col = row + (col+1)//9, (col + 1) % 9
                    if self.fill(new_row, new_col, record):
                        return True
                    record.pop()
                    self.col[col].remove(num)
                    self.row[row].remove(num)
                    self.squares[(row//3)*3 + col//3].remove(num)
        else:
            new_row, new_col = row + (col+1)//9, (col + 1) % 9
            if self.fill(new_row, new_col, record):
                return True

    def solveSudoku(self, board: list) -> None:
        """
        Do not return anything, modify board in-place instead.
        """
        self.board = board
        for i in range(9):
            self.col.append(set())
            self.row.append(set())
            self.squares.append(set())
        for row in range(9):
            for col in range(9):
                if board[row][col] != ".":
                    self.col[col].add(int(board[row][col]))
                    self.row[row].add(int(board[row][col]))
                    self.squares[(row//3)*3 + col//3].add(int(board[row][col]))
        record = []
        x = 0
        self.fill(0, 0, record)
        for i in range(9):
            for j in range(9):
                if board[i][j] == ".":
                    board[i][j] = str(record[x])
                    x += 1
        # print(board)

if __name__ == '__main__':
    s = Solution()
    s.solveSudoku([["5","3",".",".","7",".",".",".","."],
                   ["6",".",".","1","9","5",".",".","."],
                   [".","9","8",".",".",".",".","6","."],
                   ["8",".",".",".","6",".",".",".","3"],
                   ["4",".",".","8",".","3",".",".","1"],
                   ["7",".",".",".","2",".",".",".","6"],
                   [".","6",".",".",".",".","2","8","."],
                   [".",".",".","4","1","9",".",".","5"],
                   [".",".",".",".","8",".",".","7","9"]])

