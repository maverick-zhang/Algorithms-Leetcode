class Solution:

    def __init__(self):
        self.direction = ((0, 1), (0, -1), (1, 0), (-1, 0))
        self.visited = []
        self.x_max = 0
        self.y_max = 0

    def in_area(self, x, y):
        return 0 <= x < self.x_max and 0 <= y < self.y_max

    def flood(self, x, y, grid):
        self.visited[x][y] = True
        for i in range(4):
            new_x = x + self.direction[i][0]
            new_y = y + self.direction[i][1]
            if self.in_area(new_x, new_y) and grid[new_x][new_y] == "1" and not self.visited[new_x][new_y]:
                self.flood(new_x, new_y, grid)

    def numIslands(self, grid: list) -> int:
        if not grid:
            return 0

        res = 0

        self.x_max = len(grid)
        self.y_max = len(grid[0])
        for i in range(self.x_max):
            self.visited.append([False] * self.y_max)

        for i in range(self.x_max):
            for j in range(self.y_max):
                if grid[i][j] == "1" and not self.visited[i][j]:
                    self.flood(i, j, grid)
                    res += 1
        return res

if __name__ == '__main__':
    s = Solution()
    print(s.numIslands(
        [["1", "1", "0", "0", "0"], ["1", "1", "0", "0", "0"], ["0", "0", "1", "0", "0"], ["0", "0", "0", "1", "1"]]))