//
// Created by maverick on 2019/12/25.
//

#ifndef ALGORITHMS_Q447_NUMBER_OF_BOOMERANG_H
#define ALGORITHMS_Q447_NUMBER_OF_BOOMERANG_H

#include <vector>
#include <unordered_map>
using namespace std;

//给定平面上 n 对不同的点，“回旋镖” 是由点表示的元组 (i, j, k) ，其中 i 和 j 之间的距离和 i 和 k 之间的距离相等（需要考虑元组的顺序）。
//
//找到所有回旋镖的数量。你可以假设 n 最大为 500，所有点的坐标在闭区间 [-10000, 10000] 中。
//
//示例:
//
//输入:
//[[0,0],[1,0],[2,0]]
//
//输出:
//2
//
//解释:
//两个回旋镖为 [[1,0],[0,0],[2,0]] 和 [[1,0],[2,0],[0,0]]

class Solution {
public:
    int numberOfBoomerangs(vector<vector<int>>& points) {
        int res = 0;

        for (int i = 0; i < points.size(); ++i) {
            unordered_map<int, int> dist;

            for (int j = 0; j < points.size(); ++j) {
                //使用两层遍历，找到所有点距离点i的距离
                //把距离放到字典中，key为距离的平方(这样不会存在浮点失真)，value为距离的可能数
                //最后的结果即为每一个value进行Cn2组合(为1时组合为0)n*(n-1)
                //时间复杂度O(N^2)
            if (j != i)
            {
                int d = (points[i][0] - points[j][0]) * (points[i][0] - points[j][0]) +
                        (points[i][1] - points[j][1]) * (points[i][1] - points[j][1]);
                dist[d] ++;
            }

            }
            for (auto & p: dist)
                res += p.second * (p.second-1);

        }

        return res;


    }
};



#endif //ALGORITHMS_Q447_NUMBER_OF_BOOMERANG_H
