//
// Created by maverick on 2019/12/26.
//

#ifndef ALGORITHMS_Q219_CONTAIN_DUPLICATE2_H
#define ALGORITHMS_Q219_CONTAIN_DUPLICATE2_H

#include <unordered_set>
#include <vector>
using namespace std;


//给定一个整数数组和一个整数 k，判断数组中是否存在两个不同的索引 i 和 j，使得 nums [i] = nums [j]，并且 i 和 j 的差的绝对值最大为 k。
//
//示例 1:
//
//输入: nums = [1,2,3,1], k = 3
//输出: true

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {

        //使用一个滑动窗口[l ,r] r-l = k - 1，并把这中间的k个元素都放进查询表中，移动右窗口
        //如果nums[r+l]在查询集中即代表已经找到返回true，否则从查询集中删除左端的元素

        if (k < 1 or nums.size() < 2)
            return false;

        int r = k - 1, l = 0;
        unordered_set<int> record;

        for (int i = 0; i < nums.size()and i < k; ++i) {
            if (record.find(nums[i]) != record.end())
                return true;
            record.insert(nums[i]);
        }
        while (r + 1 < nums.size())
        {
            if (record.find(nums[r + 1]) != record.end())
                return true;
            record.insert(nums[r + 1]);
            r ++;
            record.erase(nums[l]);
            l ++;
        }
        return false;
    }
};



#endif //ALGORITHMS_Q219_CONTAIN_DUPLICATE2_H
