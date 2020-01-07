//
// Created by maverick on 2020/1/7.
//

#ifndef ALGORITHMS_Q47_PERMUTE_UNIQUE_H
#define ALGORITHMS_Q47_PERMUTE_UNIQUE_H

//给定一个可包含重复数字的序列，返回所有不重复的全排列。
//
//示例:
//
//输入: [1,1,2]
//输出:
//[
//[1,1,2],
//[1,2,1],
//[2,1,1]
//]

#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
private:
    vector<vector<int>> res;
    unordered_map<int, int> num_map;
    vector<bool> used;

    void __permute(vector<int> &vt, int size)
    {
        if (vt.size() == size)
        {
            res.push_back(vt);
            return;
        }

        for (auto & a_pair: num_map) {
            if (a_pair.second != 0)
            {
                vt.push_back(a_pair.first);
                a_pair.second --;
                __permute(vt, size);
                vt.pop_back();
                a_pair.second ++;
            }
        }

    }

public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {

        for (int num : nums)
            num_map[num] ++;
        vector<int> vt;
        __permute(vt, nums.size());

        return res;

    }
};

#endif //ALGORITHMS_Q47_PERMUTE_UNIQUE_H
