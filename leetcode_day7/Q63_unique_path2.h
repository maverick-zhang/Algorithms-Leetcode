//
// Created by maverick on 2020/1/9.
//

#ifndef ALGORITHMS_Q63_UNIQUE_PATH2_H
#define ALGORITHMS_Q63_UNIQUE_PATH2_H

//一个机器人位于一个 m x n 网格的左上角 （起始点在下图中标记为“Start” ）。
//
//机器人每次只能向下或者向右移动一步。机器人试图达到网格的右下角（在下图中标记为“Finish”）。
//
//现在考虑网格中有障碍物。那么从左上角到右下角将会有多少条不同的路径？

#include <vector>
using namespace std;

class Solution {

    vector<vector<long long>> memo;

public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {

        int n = obstacleGrid.size();
        int m = obstacleGrid[0].size();
        if (obstacleGrid[n-1][m-1] == 1)
            return 0;
        memo = vector<vector<long long>>(n + 1, vector<long long>(m + 1, -1));
        memo[n][m] = 1;
        memo[n][m-1] = 1;
        memo[n-1][m] = 1;
        for (int i = n; i >= 1 ; --i) {
            for (int j = m; j >= 1 ; --j) {

                if (obstacleGrid[i - 1][j - 1] == 1)
                {
                    memo[i][j] = 0;
                    continue;
                }

                if (memo[i][j] == -1)
                {
                    if (i == n and j < m)
                        memo[i][j] = memo[i][j+1];
                    else if (j == m and i < n)
                        memo[i][j] = memo[i+1][j];
                    else
                        memo[i][j] = memo[i+1][j] + memo[i][j+1];
                }

            }
        }
        return memo[1][1];

    }
};


#endif //ALGORITHMS_Q63_UNIQUE_PATH2_H
