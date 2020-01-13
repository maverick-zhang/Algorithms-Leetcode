 //
// Created by maverick on 2020/1/10.
//

#ifndef ALGORITHMS_Q416_PARTITION_EQUAL_SUBSET_H
#define ALGORITHMS_Q416_PARTITION_EQUAL_SUBSET_H

// 给定一个只包含正整数的非空数组。是否可以将这个数组分割成两个子集，使得两个子集的元素和相等。
//
// 注意:
//
// 每个数组中的元素不会超过 100
// 数组的大小不会超过 200

#include <vector>
using namespace std;


//递归解法
//这其实是一个背包问题，背包的总容量为sum(nums)/2
 class Solution {

     vector<vector<int>> memo;
     //返回在n个数字中能否找到解，起始时 n = nums.size()-1
     bool can_partition(vector<int>& nums, int capacity, int n)
     {
         if (capacity == 0)
             return true;
         if (capacity < 0 or n < 0)
             return false;

         if (memo[n][capacity] != -1)
             return memo[n][capacity];

         memo[n][capacity] =  can_partition(nums, capacity, n - 1) or
                can_partition(nums, capacity - nums[n], n -1);
         return memo[n][capacity];
     }

 public:
     bool canPartition(vector<int>& nums) {

         int sum_nums = 0;
         for (int i = 0; i < nums.size(); ++i) {
             sum_nums += nums[i];
         }
         if (sum_nums % 2 == 1)
             return false;
         int C = sum_nums/2;
         memo = vector<vector<int>>(nums.size(), vector<int> (C+1, -1));
         return can_partition(nums, C, nums.size()-1);
     }
 };


 //非递归解法
 class Solution2
 {
 public:
     bool canPartition(vector<int> &nums)
     {
         int sum_nums = 0;
         for (int i = 0; i < nums.size(); ++i) {
             sum_nums += nums[i];
         }
         if (sum_nums % 2 == 1)
             return false;
         int C = sum_nums/2;
         vector<bool> memo (C+1, false);

         //背包中只含有一个元素的时候
         for (int k = 0; k <= C; ++k) {
             memo[k] = (nums[0] == k);
         }

         //背包中大于一个元素
         for (int j = 1; j < nums.size(); ++j) {
             for (int i = C; i >= nums[j]; --i) {
                 memo[i] = (memo[i] or (memo[i - nums[j]]));
             }
         }
         return memo[C];
     }
 };


#endif //ALGORITHMS_Q416_PARTITION_EQUAL_SUBSET_H
