//
// Created by maverick on 2020/1/7.
//

#ifndef ALGORITHMS_Q90_SUBSETS_WITH_DUPLICATE_H
#define ALGORITHMS_Q90_SUBSETS_WITH_DUPLICATE_H

//给定一个可能包含重复元素的整数数组 nums，返回该数组所有可能的子集（幂集）。
//
//说明：解集不能包含重复的子集

#include <vector>
#include <algorithm>
using namespace std;


class Solution {
private:
    vector<vector<int>> res;


    //具有i个元素的子集
    void __subsets(vector<int> nums, int i, int index, vector<int> & vt)
    {
        if (vt.size() == i)
        {
            res.push_back(vt);
            return;
        }

        if (index >= nums.size())
            return;

        for (int j = index; j < nums.size(); ++j) {
            if (j > index and nums[j] == nums[j - 1])
                continue;
            vt.push_back(nums[j]);
            __subsets(nums, i, j + 1, vt);
            vt.pop_back();
        }
    }

public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {

        sort(nums.begin(), nums.end());
        for (int i = 0; i <= nums.size(); ++i) {
            vector<int> vt;
            __subsets(nums, i, 0, vt);
        }
        return res;
    }
};

#endif //ALGORITHMS_Q90_SUBSETS_WITH_DUPLICATE_H
