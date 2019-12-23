//
// Created by maverick on 2019/12/23.
//

#ifndef ALGORITHMS_Q80_REMOVE_DUPLICATED_ELM2_H
#define ALGORITHMS_Q80_REMOVE_DUPLICATED_ELM2_H

#include <vector>
using namespace std;

//给定一个排序数组，你需要在原地删除重复出现的元素，使得每个元素最多出现两次，返回移除后数组的新长度。
//
//不要使用额外的数组空间，你必须在原地修改输入数组并在使用 O(1) 额外空间的条件下完成。
//
//示例 1:
//
//给定 nums = [1,1,1,2,2,3],
//
//函数应返回新长度 length = 5, 并且原数组的前五个元素被修改为 1, 1, 2, 2, 3 。
//
//你不需要考虑数组中超出新长度后面的元素。

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        //维护两个区间，其中[0,k)为含有不超过另个重复元素的数组
        //[k,i)为和前面区间当中重复超过两次的元素，i为当前遍历的元素

        if (nums.size() == 0)
            return 0;
        int k = 1;
        for (int i = 1; i < nums.size(); ++i) {


            if (nums[i] > nums[k-1])
                swap(nums[i], nums[k++]);
            else if (nums[i] == nums[k-1])
            {
                if (k-2 < 0)
                {
                    k++;
                    continue;
                }
                if (nums[k-2] != nums[i])
                {
                    if (k != i)
                        swap(nums[i], nums[k++]);
                    else
                        k++;
                }

            }
        }

        return k;

    }
};

#endif //ALGORITHMS_Q80_REMOVE_DUPLICATED_ELM2_H
