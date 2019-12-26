//
// Created by maverick on 2019/12/23.
//

#ifndef ALGORITHMS_Q209_MINIMUM_SIZE_SUBARRAY_SUM_H
#define ALGORITHMS_Q209_MINIMUM_SIZE_SUBARRAY_SUM_H

#include <vector>
using namespace std;

//给定一个含有 n 个正整数的数组和一个正整数 s ，找出该数组中满足其和 ≥ s 的长度最小的连续子数组。如果不存在符合条件的连续子数组，返回 0。
//
//示例: 
//
//输入: s = 7, nums = [2,3,1,2,4,3]
//输出: 2
//解释: 子数组 [4,3] 是该条件下的长度最小的连续子数组。

class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {

        //解题思路，使用一个滑动窗口[l, r]代表当前的连续子数组
        //如果当前的子数组的和小于s那么左端不动，右端向右滑动直到滑到满足要求，此时再记录下长度
        //子数组符合要求之后，左端口再向右滑动直到不满足要求，过程中不断记录窗口的长度。

        int l = 0, r = -1;            //初始的窗口的长度为空
        int len = nums.size() + 1;    //初始下的子数组的长度为数组长度加一代表没有找到相应的子数组
        int sum = 0;


        while (l < nums.size())       //循环结束的条件为左窗口无法继续滑动
        {
            if (sum < s and r + 1 < nums.size())
            {
                r ++;
                sum += nums[r];
            }

            else
            {
                sum -= nums[l];
                l ++;
            }

            if (sum >= s)
                len = min(len, r - l + 1);
        }

        if (len == nums.size() + 1)
            return 0;
        else
            return len;



    }
};

#endif //ALGORITHMS_Q209_MINIMUM_SIZE_SUBARRAY_SUM_H
