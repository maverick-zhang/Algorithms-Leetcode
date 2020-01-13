//
// Created by maverick on 2020/1/9.
//

#ifndef ALGORITHMS_Q64_GRID_PATH_H
#define ALGORITHMS_Q64_GRID_PATH_H

//给定一个包含非负整数的 m x n 网格，请找出一条从左上角到右下角的路径，使得路径上的数字总和为最小。
//
//说明：每次只能向下或者向右移动一步。
//
//示例:
//
//输入:
//[
//[1,3,1],
//[1,5,1],
//[4,2,1]
//]
//输出: 7
//解释: 因为路径 1→3→1→1→1 的总和最小。

#include <vector>
using namespace std;

class Solution {
    vector<vector<int>> memo;
public:
    int minPathSum(vector<vector<int>>& grid) {

        int rows = grid.size();
        int cols = grid[0].size();
        memo = vector<vector<int>> (rows, vector<int>(cols, -1));
        memo[rows-1][cols-1] = grid[rows-1][cols-1];

        for (int i = rows - 1; i >= 0 ; --i) {
            for (int j = cols - 1; j >= 0 ; --j) {
                if (memo[i][j] == -1)
                {
                    if (i+1<rows and j+ 1 < cols)
                        memo[i][j] = grid[i][j] + min(memo[i][j+1], memo[i+1][j]);
                    else if (i+ 1 < rows)
                        memo[i][j] = grid[i][j] + memo[i+1][j];
                    else
                        memo[i][j] = grid[i][j] + memo[i][j+1];
                }
            }

        }
        return memo[0][0];
    }
};

#endif //ALGORITHMS_Q64_GRID_PATH_H
