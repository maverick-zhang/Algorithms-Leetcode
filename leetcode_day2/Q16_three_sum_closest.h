//
// Created by maverick on 2019/12/25.
//

#ifndef ALGORITHMS_Q16_THREE_SUM_CLOSEST_H
#define ALGORITHMS_Q16_THREE_SUM_CLOSEST_H

#include <vector>
#include <map>
#include <algorithm>
using namespace std;


//给定一个包括 n 个整数的数组 nums 和 一个目标值 target。找出 nums 中的三个整数，
//使得它们的和与 target 最接近。返回这三个数的和。假定每组输入只存在唯一答案。
//
//例如，给定数组 nums = [-1，2，1，-4], 和 target = 1.
//
//与 target 最接近的三个数的和为 2. (-1 + 2 + 1 = 2).

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int len_nums = nums.size();

        sort(nums.begin(), nums.end());
        int min, l, r;

        min = nums[0] + nums[1] + nums[2];

        for (int i = 0; i < len_nums; ++i) {
            while (i > 0 and i < len_nums and nums[i] == nums[i - 1])
                i ++;
            l = i + 1, r = len_nums - 1;
            while (l < r)
            {
                if (nums[i] + nums[l] + nums[r] == target)
                    return target;


                while (nums[i] + nums[l] + nums[r] < target and l < r)
                {
                    if (abs(target - (nums[i] + nums[l] + nums[r])) < abs(target - min))
                        min = nums[i] + nums[l] + nums[r];
                    l ++;

                }

                while (nums[i] + nums[l] + nums[r] > target and l < r)
                {
                    if (abs(target - (nums[i] + nums[l] + nums[r])) < abs(target - min))
                        min = nums[i] + nums[l] + nums[r];
                    r --;
                }
            }
        }
        return min;
    }
};

#endif //ALGORITHMS_Q16_THREE_SUM_CLOSEST_H
