class Solution:

    # 思路：从边界的'O'向内flood，把所有flood到的点标记为1，剩余的'O'即是被包围的
    def __init__(self):
        self.direction = ((0, 1), (0, -1), (1, 0), (-1, 0))
        self.visited = []
        self.o_map = []
        self.y_max = 0
        self.x_max = 0

    def in_area(self, x, y):
        return 0 <= x < self.x_max and 0 <= y < self.y_max

    def flood(self, x, y):
        self.o_map[x][y] = 0
        for i in range(4):
            new_x = x + self.direction[i][0]
            new_y = y + self.direction[i][1]
            if self.in_area(new_x, new_y) and not self.visited[new_x][new_y] and self.o_map[new_x][new_y] == 1:
                self.flood(new_x, new_y)

    def solve(self, board: list) -> None:
        """
        Do not return anything, modify board in-place instead.
        """
        if not board:
            return
        self.x_max = len(board)
        self.y_max = len(board[0])

        for i in range(self.x_max):
            self.o_map.append([])
            self.visited.append([False] * self.y_max)
            for j in range(self.y_max):
                if board[i][j] == "O":
                    self.o_map[i].append(1)
                else:
                    self.o_map[i].append(-1)


        for i in range(self.x_max):
            for j in range(self.y_max):
                if i == 0 or j == 0 or i == self.x_max -1 or j == self.y_max -1:
                    if board[i][j] == "O" and not self.visited[i][j]:
                        self.flood(i, j)

        for i in range(self.x_max):
            for j in range(self.y_max):
                if self.o_map[i][j] == 1:
                    board[i][j] = "X"


