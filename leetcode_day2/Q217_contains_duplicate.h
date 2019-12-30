//
// Created by maverick on 2019/12/26.
//

#ifndef ALGORITHMS_Q217_CONTAINS_DUPLICATE_H
#define ALGORITHMS_Q217_CONTAINS_DUPLICATE_H

#include <vector>
#include <unordered_set>

using namespace std;



//给定一个整数数组，判断是否存在重复元素。
//
//如果任何值在数组中出现至少两次，函数返回 true。如果数组中每个元素都不相同，则返回 false。
//
//示例 1:
//
//输入: [1,2,3,1]
//输出: true


class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {

        unordered_set<int> record;

        for (int i = 0; i < nums.size(); ++i) {
            if (record.find(nums[i]) != record.end())
                return true;
            else
                record.insert(nums[i]);
        }
        return false;
    }
};

#endif //ALGORITHMS_Q217_CONTAINS_DUPLICATE_H
