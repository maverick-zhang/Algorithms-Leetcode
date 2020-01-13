//
// Created by maverick on 2020/1/9.
//

#ifndef ALGORITHMS_Q309_BUY_SOCK_H
#define ALGORITHMS_Q309_BUY_SOCK_H

//给定一个整数数组，其中第 i 个元素代表了第 i 天的股票价格 。​
//
//设计一个算法计算出最大利润。在满足以下约束条件下，你可以尽可能地完成更多的交易（多次买卖一支股票）:
//
//你不能同时参与多笔交易（你必须在再次购买前出售掉之前的股票）。
//卖出股票后，你无法在第二天买入股票 (即冷冻期为 1 天)。

#include <vector>
using namespace std;


//此题解答时间较为久，可以优化
//股票系列问题
// https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock-with-cooldown/solution/yi-ge-fang-fa-tuan-mie-6-dao-gu-piao-wen-ti-by-lab/

class Solution {

    vector<int> memo;

    //返回第day天买和不买的最大利润
    //假定手上之前的股票已经全部出售
    int max_profit(vector<int>& prices, int day)
    {
        //最后一天不会再买入
        if (day >= prices.size() -1 )
            return 0;
        if (memo[day] != -1)
            return memo[day];
        //2：选择不买入
        int profit2 = max_profit(prices, day+1);
        //1:选择买入
        //在买入后，第i天选择出售
        int profit1 = 0;
        for (int i = day + 1; i < prices.size() ; ++i) {
            int temp_profit = prices[i] - prices[day] + max_profit(prices, i+2);
            if (temp_profit > profit1)
                profit1 = temp_profit;
        }

        memo[day] = max(profit1, profit2);
        return memo[day];
    }
public:
    int maxProfit(vector<int>& prices) {
        if (prices.empty())
            return 0;
        memo = vector<int> (prices.size(), -1);

        return max_profit(prices, 0);
    }
};



#endif //ALGORITHMS_Q309_BUY_SOCK_H
