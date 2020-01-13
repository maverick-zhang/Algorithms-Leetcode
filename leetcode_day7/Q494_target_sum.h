//
// Created by maverick on 2020/1/10.
//

#ifndef ALGORITHMS_Q494_TARGET_SUM_H
#define ALGORITHMS_Q494_TARGET_SUM_H

//给定一个非负整数数组，a1, a2, ..., an, 和一个目标数，S。现在你有两个符号 + 和 -。对于数组中的任意一个整数，你都可以从 + 或 -中选择一个符号添加在前面。
//
//返回可以使最终数组和为目标数 S 的所有添加符号的方法数。
//
//示例 1:
//
//输入: nums: [1, 1, 1, 1, 1], S: 3
//输出: 5
//解释:
//
//-1+1+1+1+1 = 3
//+1-1+1+1+1 = 3
//+1+1-1+1+1 = 3
//+1+1+1-1+1 = 3
//+1+1+1+1-1 = 3
//
//一共有5种方法让最终目标和为3。

#include <vector>
#include <unordered_map>
using namespace std;


//递归方法
class Solution {

    unordered_map<string, unsigned long> memo;

    unsigned long find_target(vector<int>& nums, int index, unsigned long S)
    {
        if (S == 0 and index == nums.size())
            return 1;
        if (index >= nums.size())
            return 0;
        string key = to_string(S)+":"+to_string(index);
        if (memo.find(key) != memo.end())
            return memo[key];

        unsigned long add = find_target(nums, index + 1, S + nums[index]);
        unsigned long minor = find_target(nums, index + 1, S - nums[index]);
        memo[key] = add + minor;
        return memo[key];
    }

public:
    int findTargetSumWays(vector<int>& nums, int S) {

        return find_target(nums, 0, S);

    }
};


//动态规划

class Solution2 {
public:
    int findTargetSumWays(vector<int>& nums, int S) {
        long sum = 0;
        for (const int &it : nums) sum += it;
        if ((S + sum) % 2 == 1 || S > sum) return 0;
        S = (S + sum) / 2;
        vector<vector<int >>dp (S+1, vector<int>(nums.size(), 0));

        //从n个元素中取若干个，使得其和恰好为S,有多少种取法
        //等价于从n-1个元素中取若干个，使得其和为S或S-nums[n]
        //状态转移方程dp[S][n] = dp[S][n-1] + dp[S-nums[n]][n-1]

        //背包中只有一个
        dp[0][0] = 1;
        dp[nums[0]][0] = 1;


        for (int i = 1; i < nums.size(); ++i) {
            for (int j = S; j >= nums[i] ; --j) {
                dp[j][i] = dp[j][i-1]  + dp[j-nums[i]][i];
            }
        }

        int ans = dp[S][nums.size()-1];
        return ans;

        //空间优化
        // vector<int>dp(S+1, 0);
        // dp[0] = 1
        // dp[nums[0]] = 1
        // for(int i = 1; i < nums.size();i++)
        //     for(int j = S; j>= nums[i]; j--)
        //          dp[j] = dp[j] + dp[j-nums[i]]

    }
};



#endif //ALGORITHMS_Q494_TARGET_SUM_H
