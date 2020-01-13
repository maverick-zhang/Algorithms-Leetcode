//
// Created by maverick on 2020/1/9.
//

#ifndef ALGORITHMS_Q120_TRIANGLE_PATH_H
#define ALGORITHMS_Q120_TRIANGLE_PATH_H

//给定一个三角形，找出自顶向下的最小路径和。每一步只能移动到下一行中相邻的结点上。
//
//例如，给定三角形：
//
//[
//[2],
//[3,4],
//[6,5,7],
//[4,1,8,3]
//]
//自顶向下的最小路径和为 11（即，2 + 3 + 5 + 1 = 11）。

#include <vector>
using namespace std;


//分析：起始点是固定为2，然后就是要寻找从3为顶点的三角形寻找最小的值
//再次递归为从6,5为顶点的最短路径问题
class Solution {

    vector<vector<int>> memo;
    //递归：自顶向下
    //寻找从第row层，col列的位置向下的最短路径
//    int find_path(vector<vector<int>>& triangle, int row, int col)
//    {
//        if (row == triangle.size() - 1)
//            return triangle[row][col];
//        if (memo[row][col] == -1)
//            memo[row][col] =  triangle[row][col] + min(find_path(triangle, row + 1, col), find_path(triangle, row + 1, col + 1));
//        return memo[row][col];
//    }

public:
    int minimumTotal(vector<vector<int>>& triangle) {

        memo = vector<vector<int>>(triangle.size(), vector<int>(triangle.size(),-1));

        int last_row = triangle.size() -1;

        //非递归：自低向上
        for (int i = 0; i < triangle[last_row].size(); ++i) {
            memo[last_row][i] = triangle[last_row][i];
        }

        for (int row = last_row - 1; row >= 0 ; --row) {
            for (int col = 0; col < triangle[row].size(); ++col) {
                memo[row][col] = triangle[row][col] + min(memo[row+1][col], memo[row+1][col+1]);
            }
        }

        return memo[0][0];

    }
};



#endif //ALGORITHMS_Q120_TRIANGLE_PATH_H
