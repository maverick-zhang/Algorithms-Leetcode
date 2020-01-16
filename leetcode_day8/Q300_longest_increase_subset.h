//
// Created by maverick on 2020/1/13.
//

#ifndef ALGORITHMS_Q300_LONGEST_INCREASE_SUBSET_H
#define ALGORITHMS_Q300_LONGEST_INCREASE_SUBSET_H

//给定一个无序的整数数组，找到其中最长上升子序列的长度。
//
//示例:
//
//输入: [10,9,2,5,3,7,101,18]
//输出: 4
//解释: 最长的上升子序列是 [2,3,7,101]，它的长度是 4。

#include <vector>
using namespace std;

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {

        if (nums.empty())
            return 0;

        vector<int> memo(nums.size(), 1);
        for (int i = 1; i < nums.size(); ++i) {
            for (int j = 0; j < i; ++j) {
                if (nums[i] > nums[j])
                    memo[i] = max(memo[i], memo[j] + 1);
            }
        }

        int res = 1;
        for (int k = 0; k < nums.size(); ++k) {
            res = max(res, memo[k]);
        }

        return res;

    }
};

#endif //ALGORITHMS_Q300_LONGEST_INCREASE_SUBSET_H
