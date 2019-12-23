//
// Created by maverick on 2019/12/23.
//

#ifndef ALGORITHMS_Q283_MOVE_ZEROS_H
#define ALGORITHMS_Q283_MOVE_ZEROS_H

#include <vector>
#include <algorithm>

using std::vector;
using std::swap;


class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        //遍历整个数组，把非零值和零进行交换
        //使用两个指针，[0, K)为全部非零的区间
        //[K, i)为零的区间，i为当前遍历的元素
        //测试用例：[0, 1, 0, 3, 12]

        int k = 0;
        for (int i = 0; i < nums.size() ; ++i) {
            //若当前的遍历的元素为0时，无需操作
            //若为非零的元素，则把当前元素和第一个零进行交换
            if (nums[i])
            {
                //如果K和i相等则无需进行交换
                if (k != i)
                    swap(nums[k++], nums[i]);
                else
                    k++;
            }

        }

    }
};

#endif //ALGORITHMS_Q283_MOVE_ZEROS_H
