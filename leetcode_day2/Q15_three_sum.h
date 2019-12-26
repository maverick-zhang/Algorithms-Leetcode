//
// Created by maverick on 2019/12/25.
//

#ifndef ALGORITHMS_Q15_THREE_SUM_H
#define ALGORITHMS_Q15_THREE_SUM_H

#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
using namespace std;

//给定一个包含 n 个整数的数组 nums，判断 nums 中是否存在三个元素 a，b，c ，使得 a + b + c = 0 ？找出所有满足条件且不重复的三元组。
//
//注意：答案中不可以包含重复的三元组。
//
//例如, 给定数组 nums = [-1, 0, 1, 2, -1, -4]，
//
//满足要求的三元组集合为：
//[
//[-1, 0, 1],
//[-1, -1, 2]
//]

//class Solution {
//public:
//    vector<vector<int>> threeSum(vector<int>& nums) {
//
//        //思路：先求出所有的两数之和并放到字典中，并保存两个数的索引，然后遍历数组中的元素查询其相反数是否在字典中并判断索引是否重叠
//        unordered_map<int, int> record;
//        vector<vector<int>> res;
//
//        for(int x: nums)
//            record[x] ++;
//        int target;
//        for (int i = 0; i < nums.size(); ++i) {
//            record[nums[i]] --;
//            for (int j = i + 1; j < nums.size() ; ++j) {
//                record[nums[j]] --;
//                target = -nums[i] - nums[j];
//                if (record[target] > 0)
//                {
//                    vector<int> tem {nums[i], nums[j], target};
//                    res.push_back(tem);
//                }
//                record[nums[j]] ++;
//            }
//            record[nums[i]] ++;
//        }
//
//        return res;
//    }
//};

//class Solution {
//public:
//    vector<vector<int>> threeSum(vector<int> &nums) {
//
//        unordered_set<int> set_tmp(nums.begin(), nums.end());
//        vector<int> vt(set_tmp.begin(), set_tmp.end());
//
//        vector<vector<int>> res;
//        for (int i = 0; i < vt.size(); ++i) {
//            for (int j = i + 1; j < vt.size(); ++j) {
//                for (int k = j + 1; k < vt.size(); ++k) {
//                    if (vt[i] + vt[j] + vt[k] == 0)
//                    {
//                        vector<int> tmp {vt[i], vt[j], vt[k]};
//                        res.push_back(tmp);
//                    }
//                }
//            }
//        }
//        return res;
//    }
//
//};

class Solution {
public:
    vector<vector<int>> threeSum(vector<int> &nums) {

        vector<vector<int>> res;
        int len_nums = nums.size();
        if (len_nums < 3)
            return res;

        sort(nums.begin(), nums.end());

        int l, r;    //使用两个指针l, r,对区间[i+1, n-1]进行遍历
        for (int i = 0; i < len_nums; ++i) {
            if (nums[i] > 0)
                return res;
            while (i -1 >= 0 and i < len_nums and nums[i] == nums[i - 1])
                i ++;
            l = i + 1, r = len_nums - 1;
            while (l < r)
            {
                if (nums[i] + nums[l] + nums[r] == 0)
                {
                    while (l < r and nums[l] == nums[l + 1])
                        l ++;
                    while (l < r and nums[r] == nums[r - 1])
                        r --;
                    vector<int> tem {nums[i], nums[l], nums[r]};
                    res.push_back(tem);
                    l ++;
                    r --;
                }
                else if (nums[i] + nums[l] + nums[r] < 0)
                    l ++;
                else
                    r --;
            }

        }

        return  res;
    }

};


#endif //ALGORITHMS_Q15_THREE_SUM_H
