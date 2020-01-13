//
// Created by maverick on 2020/1/9.
//

#ifndef ALGORITHMS_Q70_CLIMB_STAIRS_H
#define ALGORITHMS_Q70_CLIMB_STAIRS_H

#include <vector>

//假设你正在爬楼梯。需要 n 阶你才能到达楼顶。
//
//每次你可以爬 1 或 2 个台阶。你有多少种不同的方法可以爬到楼顶呢？
//
//注意：给定 n 是一个正整数。
//
//示例 1：
//
//输入： 2
//输出： 2
//解释： 有两种方法可以爬到楼顶。
//1.  1 阶 + 1 阶
//2.  2 阶

using namespace std;

class Solution {
    //使用动态规划从小到大计算出爬i阶楼梯的方法，其等于i-1的方法数和i-2的方法数之和
    //
    vector<int> memo;
public:
    int climbStairs(int n) {
        memo = vector<int>(n + 1, -1);
        memo[0] = memo[1] = 1;
        for (int i = 2; i <= n ; ++i) {
            memo[i] = memo[i-1] + memo[i - 2];
        }
        return memo[n];
    }
};



#endif //ALGORITHMS_Q70_CLIMB_STAIRS_H
