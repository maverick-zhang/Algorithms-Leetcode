//
// Created by maverick on 2019/12/25.
//

#ifndef ALGORITHMS_Q149_H
#define ALGORITHMS_Q149_H

#include <vector>
#include <unordered_map>

using namespace std;

//给定一个二维平面，平面上有 n 个点，求最多有多少个点在同一条直线上。
//
//示例 1:
//
//输入: [[1,1],[2,2],[3,3]]
//输出: 3
//解释:
//^
//|
//|        o
//|     o
//|  o  
//+------------->
//0  1  2  3  4

class Solution {

private:
    int gcd(int a, int b) {
        while (b != 0) {
            int temp = a % b;
            a = b;
            b = temp;
        }
        return a;
    }

public:
    int maxPoints(vector<vector<int>>& points) {

        //计算出所有可能的线
        int point_num = points.size();
        if (point_num <= 2)
            return point_num;

        unordered_map<pair<vector<int>, vector<int>>, int> lines;    //key:点a和点b, value:该直线上的点(>=2)

        lines.insert(make_pair(make_pair(points[0], points[1]), 2));

        for (int i = 2; i < point_num; ++i) {
//                if ()  TODO
        }


    }
};



#endif //ALGORITHMS_Q149_H
