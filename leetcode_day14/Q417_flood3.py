# 给定下面的 5x5 矩阵:
#
#  太平洋 ~   ~   ~   ~   ~
# ~   1   2   2   3  (5) *
# ~   3   2   3  (4) (4) *
# ~   2   4  (5)  3   1  *
# ~  (6) (7)  1   4   5  *
# ~  (5)  1   1   2   4  *
#    *   *   *   *   * 大西洋



class Solution:
    # 算法思路，从天平洋边界flood，对flood的点标记，再从大西洋一侧flood再进行标记，最后统计被标记了两次的点

    def __init__(self):
        self.visited_p = []
        self.visited_a = []
        self.direction = ((1, 0), (0, 1), (-1, 0), (0, -1))
        self.mark = []
        self.x_max = 0
        self.y_max = 0

    def in_area(self, x, y):
        return 0 <= x < self.x_max and 0 <= y < self.y_max

    def flood(self, x, y, matrix, is_p):
        if is_p:
            visited = self.visited_p
        else:
            visited = self.visited_a
        self.mark[x][y] += 1
        visited[x][y] = True

        for i in range(4):
            new_x = x + self.direction[i][0]
            new_y = y + self.direction[i][1]
            if self.in_area(new_x, new_y) and not visited[new_x][new_y]:
                if matrix[new_x][new_y] >= matrix[x][y]:
                    self.flood(new_x, new_y, matrix, is_p)


    def pacificAtlantic(self, matrix: list) -> list:
        if not matrix:
            return []

        self.x_max = len(matrix)
        self.y_max = len(matrix[0])

        for i in range(self.x_max):
            self.visited_p.append([False] * self.y_max)
            self.visited_a.append([False] * self.y_max)
            self.mark.append([0] * self.y_max)

        for i in range(self.x_max):
            for j in range(self.y_max):
                if (i == 0 or j == 0) and not self.visited_p[i][j] :
                    self.flood(i, j, matrix, 1)
                if (i == self.x_max - 1 or j == self.y_max - 1) and not self.visited_a[i][j]:
                    self.flood(i, j, matrix, 0)
        res = []
        for i in range(self.x_max):
            for j in range(self.y_max):
                if self.mark[i][j] == 2:
                    res.append([i, j])
        return res
