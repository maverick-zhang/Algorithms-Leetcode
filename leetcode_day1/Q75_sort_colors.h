//
// Created by maverick on 2019/12/23.
//

#ifndef ALGORITHMS_Q75_SORT_COLORS_H
#define ALGORITHMS_Q75_SORT_COLORS_H

//给定一个包含红色、白色和蓝色，一共 n 个元素的数组，原地对它们进行排序，使得相同颜色的元素相邻，并按照红色、白色、蓝色顺序排列。
//
//此题中，我们使用整数 0、 1 和 2 分别表示红色、白色和蓝色。
//
//注意:
//不能使用代码库中的排序函数来解决这道题。

#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    void sortColors(vector<int>& nums) {

        //思路1：使用计数排序，使用一个数组记录nums中为0,1,2元素的个数,然后再把nums数组中设置相应个数的0,1,2
        //思路2：使用三路快排的思路,定义三个指针zero,two, 和i,把数组分成三个区间，其中[0, zero]为全为0的部分
        //[zero + 1, i)为等于1的部分，[i, two]为待遍历的部分，[two, n-1]为全部为2的部分.
        int zero = -1;
        int two = nums.size();
        int i = 0;
        while (i < two)
        {
            if (nums[i] == 1)
                i++;
            else if (nums[i] == 0)
            {
                zero ++;
                swap(nums[i], nums[zero]);
                i++;
            }
            else
            {
                two --;
                swap(nums[i], nums[two]);
            }
        }

    }
};

#endif //ALGORITHMS_Q75_SORT_COLORS_H
