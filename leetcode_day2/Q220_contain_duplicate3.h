//
// Created by maverick on 2019/12/26.
//

#ifndef ALGORITHMS_Q220_CONTAIN_DUPLICATE3_H
#define ALGORITHMS_Q220_CONTAIN_DUPLICATE3_H

#include <vector>
#include <set>
using namespace std;
//给定一个整数数组，判断数组中是否有两个不同的索引 i 和 j，使得 nums [i] 和 nums [j] 的差的绝对值最大为 t，
//并且 i 和 j 之间的差的绝对值最大为 ķ。
//
//示例 1:
//
//输入: nums = [1,2,3,1], k = 3, t = 0
//输出: true

class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {



        //维护一个滑动窗口[l, r]， r-l = k - 1.在这个窗口内的全部元素均不符合题目条件,r+1是窗口的最大临界值
        //检查nums[r+1]是否和窗口中的元素的差值为t，即查找nums[r+1] - t之间的数nums[r+1] + t是否在窗口中
        //set.lower_bound(x)返回第一个大于等于x的迭代器


        set<long long> record;

        for (int i = 0; i < nums.size(); ++i) {

            if (record.lower_bound((long long)nums[i] - t) != record.end() and
                *record.lower_bound((long long)nums[i] - t) <= (long long)nums[i] + t)
                return true;

            record.insert((long long)nums[i]);

            if (record.size() == (long long)(k + 1))
                record.erase((long long)nums[i - k]);
        }
        return false;
    }
};

#endif //ALGORITHMS_Q220_CONTAIN_DUPLICATE3_H
