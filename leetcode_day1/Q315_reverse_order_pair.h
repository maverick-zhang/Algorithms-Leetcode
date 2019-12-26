//
// Created by maverick on 2019/12/13.
//

#ifndef ALGORITHMS_Q315_REVERSE_ORDER_PAIR_H
#define ALGORITHMS_Q315_REVERSE_ORDER_PAIR_H

#include <vector>
#include <algorithm>

using std::vector;



//题目描述：输出一个数组，数组的值为对应输入数组的元素的逆序对个数，即该元素右侧小于该元素的个数。
//示例：输入[5,2,6,1], 输出[2,1,1,0]
//目前的实现为返回逆序对的个数，暂未达到题目的要求。
class solution
{
    //使用归并排序解决
    //需要归并的区间为[l, r], [l, i)为左半区已经归并完成的， (j, r]为右半区归并完成的
public:
    void merge(vector<int> & nums, int & pair_count,  int l, int r)
    {
        if (l>=r)
            return;
        int mid = (l+r)/2;
        merge(nums, pair_count, l, mid);
        merge(nums, pair_count, mid + 1, r);

        vector<int> nums_copy;
        std::copy(nums.begin()+l, nums.begin() + r + 1, std::back_inserter(nums_copy));

        int i = l;
        int j = mid + 1;
        int k = l;
        while ( k <= r )
        {
            if (i == mid + 1)
            {
                nums[k] = nums_copy[j - l];
                j ++;
                k ++;
                continue;
            }
            else if (j == r + 1)
            {
                nums[k] = nums_copy[i - l];
                i ++;
                k ++;
                pair_count += j - (mid + 1);
                continue;
            }

            if (nums_copy[i - l] <= nums_copy[j - l])
            {
                nums[k] = nums_copy[i - l];
                i ++;
                k ++;
                pair_count += j - (mid + 1);
            }
            else
            {
                nums[k] = nums_copy[j - l];
                j ++;
                k ++;
            }

        }



    }
    int countSmaller(vector<int> & nums)
    {
        vector<int> output(nums.size());
        int pair_count;
        merge(nums, pair_count, 0, nums.size()-1);
        return pair_count;
    }
};

#endif //ALGORITHMS_Q315_REVERSE_ORDER_PAIR_H
