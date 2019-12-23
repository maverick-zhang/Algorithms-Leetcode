//
// Created by maverick on 2019/12/23.
//

#ifndef ALGORITHMS_Q26_REMOVE_DUPLICATED_ELM_H
#define ALGORITHMS_Q26_REMOVE_DUPLICATED_ELM_H

//给定一个排序数组，你需要在原地删除重复出现的元素，使得每个元素只出现一次，返回移除后数组的新长度。

//不要使用额外的数组空间，你必须在原地修改输入数组并在使用 O(1) 额外空间的条件下完成。

//给定 nums = [0,0,1,1,1,2,2,3,3,4],
//
//函数应该返回新的长度 5, 并且原数组 nums 的前五个元素被修改为 0, 1, 2, 3, 4。


#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {

        //维护两个区间，其中[0,k)为含有不重复元素的数组
        //[k,i)为和前面区间当中重复的元素，i为当前遍历的元素

        if (nums.size() == 0)
            return 0;
        int k = 1;
        for (int i = 0; i < nums.size(); ++i) {


            if (nums[i] > nums[k-1])
                swap(nums[i], nums[k++]);

        }

        return k;

    }
};

#endif //ALGORITHMS_Q26_REMOVE_DUPLICATED_ELM_H
