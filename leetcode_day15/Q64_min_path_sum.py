class Solution:
    def minPathSum(self, grid) -> int:
        for i in range(len(grid)-1, -1, -1):
            for j in range(len(grid[0]) - 1, -1, -1):
                if i == len(grid) -1 and j == len(grid[0]) - 1:
                    continue
                right = grid[i][j+1] if (j+1) < len(grid[0]) else float("inf")
                down = grid[i+1][j] if (i+1) < len(grid) else float("inf")
                grid[i][j] += min(right, down)
        return grid[0][0]
