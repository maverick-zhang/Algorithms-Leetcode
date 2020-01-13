//
// Created by maverick on 2020/1/9.
//

#ifndef ALGORITHMS_Q343_INTEGER_BREAK_H
#define ALGORITHMS_Q343_INTEGER_BREAK_H

#include <vector>
using namespace std;

//给定一个正整数 n，将其拆分为至少两个正整数的和，并使这些整数的乘积最大化。 返回你可以获得的最大乘积。
//
//示例 1:
//
//输入: 2
//输出: 1
//解释: 2 = 1 + 1, 1 × 1 = 1。

//把n拆分为(1, n-1), (2, n-2) ...(i, j)...(n-1, 1)这样的数对，那么最大值即为integerBreak(i) * integerBreak(j)

class Solution {
    vector<int> memo;
    int max3(int num1, int num2, int num3)
    {
        if (num1>= num2)
            return max(num1, num3);
        else
            return max(num2, num3);
    }

public:
    int integerBreak(int n) {

        memo = vector<int>(n + 1, -1);
        memo[2] = 1;
        memo[1] = 1;

        for (int i = 3; i <= n; ++i) {
            for (int j = 1; j < i; ++j) {

                //继续分拆的结果不一定有不分拆的结果大，因此要比较两个都不分拆，以及分拆一个
                //由于j从1开始，其隐含了两个都分拆的结果
                memo[i] = max3(memo[i], j * (i - j), j * memo[i - j]);
            }
        }
        return memo[n];
    }

};



#endif //ALGORITHMS_Q343_INTEGER_BREAK_H
