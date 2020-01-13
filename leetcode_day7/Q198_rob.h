//
// Created by maverick on 2020/1/9.
//

#ifndef ALGORITHMS_Q198_ROB_H
#define ALGORITHMS_Q198_ROB_H

//你是一个专业的小偷，计划偷窃沿街的房屋。每间房内都藏有一定的现金，影响你偷窃的唯一制约因素就是相邻的房屋装有相互连通的防盗系统，
//如果两间相邻的房屋在同一晚上被小偷闯入，系统会自动报警。
//
//给定一个代表每个房屋存放金额的非负整数数组，计算你在不触动警报装置的情况下，能够偷窃到的最高金额。

#include <vector>
using namespace std;


//通过递归求解
class Solution {

    vector<int> memo;

    //选择偷第index家店铺，那么所求即为在剩下的店铺中偷取最大值，在加上该店铺的金额
    //如果不偷，那么下一次可以从[index+1, n-1]偷取，否则从[index+2, n-1]偷取
    //返回[index, n-1]之间偷取的最大值
    int rob_recv(vector<int> & nums, int index)
    {
        if (index >= nums.size())
            return 0;

        if (index == nums.size() - 1)
            return nums[index];

        if (memo[index] != -1)
            return memo[index];

        int res = max(nums[index] + rob_recv(nums,index+2), rob_recv(nums, index+1));

        memo[index] = res;
        return res;

    }

public:
    int rob(vector<int>& nums) {

        memo = vector<int> (nums.size(), -1);

        return rob_recv(nums, 0);

    }
};


//非递归求解:动态规划

class Solution2
{
public:
    int rob(vector<int>& nums)
    {
        if (nums.empty())
            return 0;

        vector<int> memo(nums.size(), -1);

        int len = nums.size();

        memo[len-1] = nums[len-1];

        for (int i = len - 2; i >=0 ; --i) {
            memo[i] = max(nums[i] + (i+2<len?memo[i+2]:0), memo[i+1]);
        }
        return memo[0];


    }
};

#endif //ALGORITHMS_Q198_ROB_H
