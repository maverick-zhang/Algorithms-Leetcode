//
// Created by maverick on 2020/1/7.
//

#ifndef ALGORITHMS_Q78_SUBSETS_H
#define ALGORITHMS_Q78_SUBSETS_H

//给定一组不含重复元素的整数数组 nums，返回该数组所有可能的子集（幂集）。
//
//说明：解集不能包含重复的子集

#include <vector>
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
            vt.push_back(nums[j]);
            __subsets(nums, i, j + 1, vt);
            vt.pop_back();
        }
    }

public:
    vector<vector<int>> subsets(vector<int>& nums) {


        for (int i = 0; i <= nums.size(); ++i) {
            vector<int> vt;
            __subsets(nums, i, 0, vt);
        }
        return res;
    }
};

#endif //ALGORITHMS_Q78_SUBSETS_H
