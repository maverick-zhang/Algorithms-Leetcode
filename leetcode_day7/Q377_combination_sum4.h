//
// Created by maverick on 2020/1/10.
//

#ifndef ALGORITHMS_Q377_COMBINATION_SUM4_H
#define ALGORITHMS_Q377_COMBINATION_SUM4_H

//给定一个由正整数组成且不存在重复数字的数组，找出和为给定目标正整数的组合的个数。
//
//示例:
//
//nums = [1, 2, 3]
//target = 4
//
//所有可能的组合为：
//(1, 1, 1, 1)
//(1, 1, 2)
//(1, 2, 1)
//(1, 3)
//(2, 1, 1)
//(2, 2)
//(3, 1)
//
//请注意，顺序不同的序列被视作不同的组合。
//
//因此输出为 7。

#include <vector>
using namespace std;


//递归解法
class Solution {

    vector<int> memo;

    int combination(vector<int> & nums, int target)
    {
        if (target == 0)
            return 1;
        if (target < 0)
            return 0;

        if (memo[target] != -1)
            return memo[target];

        int res = 0;
        for (int i = 0; i < nums.size(); ++i) {
            res += combination(nums, target - nums[i]);
        }
        memo[target] = res;
        return res;

    }

public:
    int combinationSum4(vector<int>& nums, int target) {

        if (target <= 0 or nums.empty())
            return 0;

        memo = vector<int> (target+1, -1);

        combination(nums, target);

        return memo[target];


    }
};


//动态规划

//class Solution2
//{
//public:
//    int combinationSum4(vector<int> & nums, int target)
//    {
//        if (target <= 0 or nums.empty())
//            return 0;
//
//        vector<unsigned long long> memo (target+1, 0);
//        memo[0] = 1;
//
//        for (int i = 1; i <= target ; ++i) {
//            for (int j = 0; j < nums.size(); ++j) {
//                if (i - nums[j] >= 0)
//                    memo[i] += memo[i-nums[j]];
//            }
//        }
//
//
//        return memo[target];
//    }
//};

#endif //ALGORITHMS_Q377_COMBINATION_SUM4_H
