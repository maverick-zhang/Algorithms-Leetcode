//
// Created by maverick on 2020/1/7.
//

#ifndef ALGORITHMS_Q46_PERMUTATION_H
#define ALGORITHMS_Q46_PERMUTATION_H

//给定一个没有重复数字的序列，返回其所有可能的全排列。
//
//示例:
//
//输入: [1,2,3]
//输出:
//[
//[1,2,3],
//[1,3,2],
//[2,1,3],
//[2,3,1],
//[3,1,2],
//[3,2,1]
//]

#include <vector>
using namespace std;



class Solution {
private:
    vector<vector<int>> res;

    vector<bool> used;

    //递归调用的函数
    //index表示为当前需要添加到数组vt中的数字；
    void __permute(vector<int> & nums, int index, vector<int>& vt)
    {
        //递归终止条件：当vt的size和nums的size相同时表示已经得到一个全排列
        if (vt.size() == nums.size())
        {
            res.push_back(vt);
            return;
        }

        for (int i = 0; i < nums.size(); ++i) {
            if (!used[i])
            {
                vt.push_back(nums[i]);
                used[i] = true;
                __permute(nums, index + 1, vt);
                vt.pop_back();
                used[i] = false;
            }
        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {


        used = vector<bool>(nums.size(), false);
        vector<int> vt;
        __permute(nums, 0, vt);

        return res;

    }
};



#endif //ALGORITHMS_Q46_PERMUTATION_H
