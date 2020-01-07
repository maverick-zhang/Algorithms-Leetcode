//
// Created by maverick on 2020/1/7.
//

#ifndef ALGORITHMS_Q40_COMBINATION_SUM2_H
#define ALGORITHMS_Q40_COMBINATION_SUM2_H

//给定一个数组 candidates 和一个目标数 target ，找出 candidates 中所有可以使数字和为 target 的组合。
//
//candidates 中的每个数字在每个组合中只能使用一次。
//
//说明：
//
//所有数字（包括目标数）都是正整数。
//解集不能包含重复的组合。 
//示例 1:
//
//输入: candidates = [10,1,2,7,6,1,5], target = 8,
//所求解集为:
//[
//[1, 7],
//[1, 2, 5],
//[2, 6],
//[1, 1, 6]
//]

#include <vector>
#include <map>
using namespace std;


#include <vector>
#include <algorithm>
using namespace std;

class Solution {

private:
    vector<int> candidates;
    vector<vector<int>> res;
    vector<int> path;
public:
    void DFS(int start, int target) {
        if (target == 0) {
            res.push_back(path);
            return;
        }

        for (int i = start; i < candidates.size() && target - candidates[i] >= 0; i++) {
            if (i > start && candidates[i] == candidates[i - 1])
                continue;
            path.push_back(candidates[i]);
            // 元素不可重复利用，使用下一个即i+1
            DFS(i + 1, target - candidates[i]);
            path.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int> &candidates, int target) {
        sort(candidates.begin(), candidates.end());
        this->candidates = candidates;
        DFS(0, target);
        return res;
    }
};


#endif //ALGORITHMS_Q40_COMBINATION_SUM2_H
