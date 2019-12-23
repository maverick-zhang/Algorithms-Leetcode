//
// Created by maverick on 2019/12/23.
//

#ifndef ALGORITHMS_Q167_TWO_SUM2_H
#define ALGORITHMS_Q167_TWO_SUM2_H

//给定一个已按照升序排列 的有序数组，找到两个数使得它们相加之和等于目标数。
//
//函数应该返回这两个下标值 index1 和 index2，其中 index1 必须小于 index2。
//
//说明:
//
//返回的下标值（index1 和 index2）不是从零开始的。
//你可以假设每个输入只对应唯一的答案，而且你不可以重复使用相同的元素。

#include <vector>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int i = 0;
        int j = numbers.size() - 1;
        while (i < j)
        {
            if (numbers[i] + numbers[j] == target)
            {
                vector<int> res;
                res.push_back(i+1);
                res.push_back(j+1);
                return res;
            }
            else if (numbers[i] + numbers[j] > target)
                j--;
            else
                i++;
        }

    }
};

#endif //ALGORITHMS_Q167_TWO_SUM2_H
