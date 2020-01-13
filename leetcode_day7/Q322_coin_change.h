//
// Created by maverick on 2020/1/10.
//

#ifndef ALGORITHMS_Q322_COIN_CHANGE_H
#define ALGORITHMS_Q322_COIN_CHANGE_H

//给定不同面额的硬币 coins 和一个总金额 amount。编写一个函数来计算可以凑成总金额所需的最少的硬币个数。如果没有任何一种硬币组合能组成总金额，返回 -1。
//
//示例 1:
//
//输入: coins = [1, 2, 5], amount = 11
//输出: 3
//解释: 11 = 5 + 5 + 1

#include <vector>
#include <limits.h>
using namespace std;


//背包问题:capacity为amount,只不过物品为可重复

//递归方法(超出时间限制)
class Solution {

    vector<int> memo;

    //总量为amount需要的至少硬币数量
    int coin_change(vector<int>& coins, int amount)
    {
        if (amount == 0)
            return 0;
        if (amount < 0)
            return -1;

        if (memo[amount] != -1)
            return memo[amount];

        bool found = false;
        for (int i = 0; i < coins.size(); ++i) {
            int temp = coin_change(coins, amount - coins[i]);
            if (!found and temp != -1)
            {
                found = true;
                memo[amount] = temp + 1;
            }
            else if (found and temp != -1)
            {
                memo[amount] = min(memo[amount], temp + 1);
            }

        }
        return memo[amount];
    }

public:
    int coinChange(vector<int>& coins, int amount) {

        memo = vector<int> (amount + 1, -1);
        return coin_change(coins, amount);
    }
};


//非递归方法
class Solution2
{
public:
    int coinChange(vector<int>& nums, int amount)
    {
        if (nums.empty() or amount < 0)
            return -1;
        if (amount == 0)
            return 0;

        //memo[i]代表金额为i时的最小硬币数量
        vector<long> memo(amount+1, INT_MAX);
        memo[0] = 0;
        for (int coin: nums) {
            for (int i = coin; i <= amount; ++i) {
                memo[i] = min(memo[i], memo[i-coin] + 1);
            }
        }
        if (memo[amount] == INT_MAX)
            return -1;
        else
            return memo[amount];

    }
};


#endif //ALGORITHMS_Q322_COIN_CHANGE_H
