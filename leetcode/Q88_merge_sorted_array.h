//
// Created by maverick on 2019/12/23.
//

#ifndef ALGORITHMS_Q88_MERGE_SORTED_ARRAY_H
#define ALGORITHMS_Q88_MERGE_SORTED_ARRAY_H

//给定两个有序整数数组 nums1 和 nums2，将 nums2 合并到 nums1 中，使得 num1 成为一个有序数组。
//
//说明:
//
//初始化 nums1 和 nums2 的元素数量分别为 m 和 n。
//你可以假设 nums1 有足够的空间（空间大小大于或等于 m + n）来保存 nums2 中的元素。
//

#include <vector>
using namespace std;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = 0, j = 0, k=0;
        vector<int> num1_copy(nums1);
        while (k < m+n)
        {
            if (i == m)
            {
                nums1[k] = nums2[j];
                k ++;
                j ++;
            }
            else if (j == n)
            {
                nums1[k] = num1_copy[i];
                k ++;
                i ++;
            }
            else if (num1_copy[i] <= nums2[j])
            {
                nums1[k] = num1_copy[i];
                k ++;
                i ++;
            }
            else
            {
                nums1[k] = nums2[j];
                k ++;
                j ++;
            }
        }
    }
};

#endif //ALGORITHMS_Q88_MERGE_SORTED_ARRAY_H
