//
// Created by maverick on 2020/1/9.
//

#ifndef ALGORITHMS_Q279_NUM_SQUARES2_H
#define ALGORITHMS_Q279_NUM_SQUARES2_H

//给定正整数 n，找到若干个完全平方数（比如 1, 4, 9, 16, ...）使得它们的和等于 n。你需要让组成和的完全平方数的个数最少。
#include <vector>

using namespace std;

class Solution
{

private:
    vector<int> memo;

public:

    int numSquares(int n)
    {
        memo = vector<int> (n+1, -1);
        for (int i = 1; i*i <= n; ++i) {
            memo[i*i] = 1;
        }

        for (int j = 1; j <= n; ++j) {
            if (memo[j] == -1)
            {
                int min_nums = -1;
                for (int i = 1; i*i < j; ++i) {
                    if (min_nums == -1)
                        min_nums = memo[j-i*i] + 1;
                    else
                        min_nums = min(min_nums, memo[j - i * i] + 1);
                }
                memo[j] = min_nums;
            }
        }
        return memo[n];

    }
};

#endif //ALGORITHMS_Q279_NUM_SQUARES2_H
