//
// Created by maverick on 2019/12/14.
//

#ifndef ALGORITHMS_Q215_KTH_LAGEST_H
#define ALGORITHMS_Q215_KTH_LAGEST_H

#include <vector>
#include <algorithm>
#include <cstdlib>
#include <ctime>


//问题描述：求解数组中第k大的元素。
//解题思路，使用快速排序的想法，当某个元素在确定自己的位置之后，即[l, p)的元素都小于p,(p,r]的元素都大于p那么p即是第(p+1)大的元素。
//只需要继续在另外一个半区内继续寻找(k-p-1)大的元素即可。

using namespace std;

class Solution {
public:

    //使用三个指针[l, lt),[lt, i), [gt, r]分别代表小于val的部分，等于val的部分，大于val的部分。

    static int __partition(vector<int> & nums, int l, int r,  int k)
    {
        swap(nums[rand()%(r-l+1) + l], nums[l]);

        int val = nums[l];
        int lt = l;
        int gt = r + 1;
        int i = l + 1;
        while (i < gt)
        {
            if (nums[i] < val)
            {
                swap(nums[lt + 1], nums[i]);
                lt ++;
                i ++;
            }
            else if (nums[i] == val)
                i ++;
            else
            {
                swap(nums[i], nums[gt - 1]);
                gt --;
            }
        }
        swap(nums[l], nums[lt]);
        if (gt + 1 <= k)
            return __partition(nums, gt, r, k);
        else if (lt >= k)
            return __partition(nums, l, lt - 1, k);
        else
            return nums[lt];

//        return nums[lt];

    }

    static int findKthLargest(vector<int>& nums, int k) {
        int n = nums.size();
        if (n == 1)
            return nums[0];
        vector<int> num_copy(nums);
        srand(time(nullptr));
        if (k<0 or k >n)
            exit(EXIT_FAILURE);
        k = nums.size()-k+1;
        int num = __partition(num_copy, 0, n-1, k);
        return num;
    }
};

#endif //ALGORITHMS_Q215_KTH_LAGEST_H
