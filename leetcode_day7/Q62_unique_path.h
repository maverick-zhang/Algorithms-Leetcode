//
// Created by maverick on 2020/1/9.
//

#ifndef ALGORITHMS_Q62_UNIQUE_PATH_H
#define ALGORITHMS_Q62_UNIQUE_PATH_H

//一个机器人位于一个 m x n 网格的左上角 （起始点在下图中标记为“Start” ）。
//
//机器人每次只能向下或者向右移动一步。机器人试图达到网格的右下角（在下图中标记为“Finish”）。
//
//问总共有多少条不同的路径？

#include <vector>
using namespace std;



class Solution {

    vector<vector<int>> memo;

public:
    int uniquePaths(int m, int n) {

        memo = vector<vector<int>>(n + 1, vector<int>(m + 1, -1));
        memo[n][m] = 1;
        memo[n][m-1] = 1;
        memo[n-1][m] = 1;
        for (int i = n; i >= 1 ; --i) {
            for (int j = m; j >= 1 ; --j) {
                if (memo[i][j] == -1)
                {
                    if (i == n or j == m)
                    {
                        memo[i][j] = 1;
                        continue;
                    } else
                        memo[i][j] = memo[i+1][j] + memo[i][j+1];

                }
            }
        }
        return memo[1][1];
    }
};





#endif //ALGORITHMS_Q62_UNIQUE_PATH_H
