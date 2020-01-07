//
// Created by maverick on 2020/1/7.
//

#ifndef ALGORITHMS_Q200_ISLAND_NUMBER_H
#define ALGORITHMS_Q200_ISLAND_NUMBER_H

//给定一个由 '1'（陆地）和 '0'（水）组成的的二维网格，计算岛屿的数量。一个岛被水包围，
//并且它是通过水平方向或垂直方向上相邻的陆地连接而成的。你可以假设网格的四个边均被水包围。
//
//示例 1:
//
//输入:
//11110
//11010
//11000
//00000
//
//输出: 1

#include <vector>
using namespace std;

class Solution {
private:

    int direction[4][2] {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};

    int x_max, y_max;

    bool in_area(int x, int y)
    {
        return x < x_max and x >= 0 and y < y_max and y >= 0;
    }

    vector<vector<bool>> visited;

    void dfs(vector<vector<char>> & grid, int x, int y)
    {
        visited[x][y] = true;
        for (int i = 0; i < 4; ++i) {
            int new_x = x + direction[i][0];
            int new_y = y + direction[i][1];
            if (in_area(new_x, new_y) and !visited[new_x][new_y] and grid[new_x][new_y] == '1')
                dfs(grid, new_x, new_y);
        }
    }

public:
    int numIslands(vector<vector<char>>& grid) {
        x_max = grid.size();
        if (x_max == 0)
            return 0;
        y_max = grid[0].size();
        visited = vector<vector<bool>> (x_max, vector<bool>(y_max, false));
        int res = 0;
        for (int i = 0; i < x_max; ++i) {
            for (int j = 0; j < y_max; ++j) {
                if (grid[i][j] == '1' and !visited[i][j])
                {
                    res ++;
                    dfs(grid, i, j);
                }
            }
        }
        return res;

    }
};


#endif //ALGORITHMS_Q200_ISLAND_NUMBER_H
