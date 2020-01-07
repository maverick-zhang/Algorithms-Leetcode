//
// Created by maverick on 2020/1/7.
//

#ifndef ALGORITHMS_Q39_COMBINATION_SUM_H
#define ALGORITHMS_Q39_COMBINATION_SUM_H

//给定一个无重复元素的数组 candidates 和一个目标数 target ，找出 candidates 中所有可以使数字和为 target 的组合。
//
//candidates 中的数字可以无限制重复被选取。
//
//说明：
//
//所有数字（包括 target）都是正整数。
//解集不能包含重复的组合。 
//示例 1:
//
//输入: candidates = [2,3,6,7], target = 7,
//        所求解集为:
//[
//[7],
//[2,2,3]
//]

#include <vector>
using namespace std;

class Solution {
private:
    vector<vector<int>> res;

    void combination_sum(vector<int> & candidates, int index, int target, vector<int>& vt)
    {
        if (target == 0)
        {
            res.push_back(vt);
            return;
        }
        if (index >= candidates.size() or target < 0)
            return;

        for (int i = index; i < candidates.size(); ++i) {
            vt.push_back(candidates[i]);
            combination_sum(candidates, i, target - candidates[i], vt);
            vt.pop_back();
        }

    }

public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> vt;

        combination_sum(candidates, 0, target, vt);
        return res;
    }
};

#endif //ALGORITHMS_Q39_COMBINATION_SUM_H
