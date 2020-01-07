//
// Created by maverick on 2020/1/7.
//

#ifndef ALGORITHMS_Q77_COMBINATION_H
#define ALGORITHMS_Q77_COMBINATION_H

//给定两个整数 n 和 k，返回 1 ... n 中所有可能的 k 个数的组合。
//
//示例:
//
//输入: n = 4, k = 2
//输出:
//[
//[2,4],
//[3,4],
//[2,3],
//[1,2],
//[1,3],
//[1,4],
//]

#include <vector>
using namespace std;

class Solution {
private:
    vector<vector<int >> res;
    //把数组的nums[index]添加到结果数组中
    void __combine(int n, int index, vector<int>& vt, int k)
    {
        if (vt.size() == k)
        {
            res.push_back(vt);
            return;
        }

        for (int i = index; i <=n ; ++i)
        {
            vt.push_back(i);
            __combine(n, i + 1, vt, k);
            vt.pop_back();
        }
    }
public:
    vector<vector<int>> combine(int n, int k) {

        res.clear();

        if (n <= 0 or k <=0 or k > n)
            return res;
        vector<int> vt;

        __combine(n, 1, vt, k);



        return res;
    }
};

#endif //ALGORITHMS_Q77_COMBINATION_H
