//
// Created by maverick on 2019/12/25.
//

#ifndef ALGORITHMS_Q18_FOUR_SUM_H
#define ALGORITHMS_Q18_FOUR_SUM_H

#include <vector>
#include <algorithm>
using namespace std;

//给定一个包含 n 个整数的数组 nums 和一个目标值 target，判断 nums 中是否存在四个元素 a，b，c 和 d ，
//使得 a + b + c + d 的值与 target 相等？找出所有满足条件且不重复的四元组。
//
//注意：
//
//答案中不可以包含重复的四元组。

class Solution {
private:
    vector<vector<int>> res;
      void threeSum(vector<int> &nums, int target, int t2) {

        int len_nums = nums.size();
        if (len_nums < 3)
            return;


        int l, r;    //使用两个指针l, r,对区间[i+1, n-1]进行遍历
        for (int i = 0; i < len_nums; ++i) {
            while (i -1 >= 0 and i < len_nums and nums[i] == nums[i - 1])
                i ++;
            l = i + 1, r = len_nums - 1;
            while (l < r)
            {
                if (nums[i] + nums[l] + nums[r] == target)
                {
                    while (l < r and nums[l] == nums[l + 1])
                        l ++;
                    while (l < r and nums[r] == nums[r - 1])
                        r --;
                    vector<int> tem {t2, nums[i], nums[l], nums[r]};
                    res.push_back(tem);
                    l ++;
                    r --;
                }
                else if (nums[i] + nums[l] + nums[r] < target)
                    l ++;
                else
                    r --;
            }
        }
    }
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {

          sort(nums.begin(), nums.end());

          for (int i = 0; i < nums.size() ; ++i) {
              while (i - 1 >=0 and i < nums.size() and nums[i - 1] == nums[i])
                  i ++;
              if (i >= nums.size())
                  break;
              vector<int> tmp(nums.begin()+i + 1, nums.end());
              threeSum(tmp, target - nums[i], nums[i]);

          }

        return res;

    }
};

#endif //ALGORITHMS_Q18_FOUR_SUM_H
