//
// Created by maverick on 2020/1/7.
//

#ifndef ALGORITHMS_Q216_COMBINATION_SUM3_H
#define ALGORITHMS_Q216_COMBINATION_SUM3_H

//找出所有相加之和为 n 的 k 个数的组合。组合中只允许含有 1 - 9 的正整数，并且每种组合中不存在重复的数字。
//
//说明：
//
//所有数字都是正整数。
//解集不能包含重复的组合。 
//示例 1:
//
//输入: k = 3, n = 7
//输出: [[1,2,4]]
#include <vector>
using namespace std;
class Solution {

    vector<vector<int>> res;
    void __combination(int i, vector<int> & vt, int k, int n)
    {
        if (k == 0 and n == 0)
        {
            res.push_back(vt);
            return;
        }

        if (k < 0 or i > 9 or n < 0)
            return;

        for (int j = i; j < 10; ++j) {
            vt.push_back(j);
            __combination(j+1, vt, k - 1, n - j);
            vt.pop_back();
        }
    }

public:
    vector<vector<int>> combinationSum3(int k, int n) {

        vector<int> vt;
        __combination(1, vt, k, n);
        return res;
    }
};


#endif //ALGORITHMS_Q216_COMBINATION_SUM3_H
