class Solution:

    def __init__(self):
        self.direction = ((0, 1), (0, -1), (1, 0), (-1, 0))
        self.visited = []
        # y的最大取值
        self.y_max = 0
        # x 的最大取值
        self.x_max = 0

    def in_area(self, x, y):
        return 0 <= x < self.x_max and 0 <= y < self.y_max

    # 从(x, y)位置寻找word[index, n-1]的子串
    def find_word(self, word, index, x, y, board):

        if index == len(word) -1:
            return word[index] == board[x][y]

        if word[index] == board[x][y]:
            self.visited[x][y] = True
            for i in range(4):
                new_x = x + self.direction[i][0]
                new_y = y + self.direction[i][1]
                if (self.in_area(new_x, new_y) and not self.visited[new_x][new_y]):
                    if self.find_word(word, index + 1, new_x, new_y, board):
                        return True
            self.visited[x][y] = False

        return False

    def exist(self, board: list, word: str) -> bool:
        if not board:
            return False
        self.x_max = len(board)
        self.y_max = len(board[0])

        for i in range(self.x_max):
            self.visited.append([False] * self.y_max)
        for i in range(self.x_max):
            for j in range(self.y_max):
                if self.find_word(word, 0, i, j, board):
                    return True
        return False