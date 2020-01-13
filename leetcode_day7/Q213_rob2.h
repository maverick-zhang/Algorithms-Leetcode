//
// Created by maverick on 2020/1/9.
//

#ifndef ALGORITHMS_Q213_ROB2_H
#define ALGORITHMS_Q213_ROB2_H

//你是一个专业的小偷，计划偷窃沿街的房屋，每间房内都藏有一定的现金。这个地方所有的房屋都围成一圈，
//这意味着第一个房屋和最后一个房屋是紧挨着的。同时，相邻的房屋装有相互连通的防盗系统，如果两间相邻的房屋在同一晚上被小偷闯入，系统会自动报警。
//
//给定一个代表每个房屋存放金额的非负整数数组，计算你在不触动警报装置的情况下，能够偷窃到的最高金额。

#include <vector>

using namespace std;


//把问题拆解，如果不抢劫第一家房子，那么问题变成了[1, n-1](非环形)抢劫的最大值
//如果不抢劫最后一家，[0, n-2]抢劫最大值，比较这两个最大值即可
class Solution {

public:
    int rob(vector<int>& nums) {
        if (nums.empty())
            return 0;
        if (nums.size() == 1)
            return nums[0];
        vector<int> memo1(nums.size(), 0);
        vector<int> memo2(nums.size(), 0);
        int len = nums.size();
        memo1[len-1] = nums[len-1];
        memo2[len-2] = nums[len-2];

        for (int i = len -2; i >= 1 ; --i) {
            memo1[i] = max(nums[i] + (i+2<len?memo1[i+2]:0), memo1[i+1]);
        }
        for (int i = len -3; i >= 0 ; --i) {
            memo2[i] = max(nums[i] + memo2[i+2], memo2[i+1]);
        }

        return max(memo1[1], memo2[0]);

    }
};

#endif //ALGORITHMS_Q213_ROB2_H
