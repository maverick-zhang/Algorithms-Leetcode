//
// Created by maverick on 2020/1/13.
//

#ifndef ALGORITHMS_Q376_WIGGLE_SUBSEQUENCE_H
#define ALGORITHMS_Q376_WIGGLE_SUBSEQUENCE_H

//如果连续数字之间的差严格地在正数和负数之间交替，则数字序列称为摆动序列。第一个差（如果存在的话）可能是正数或负数。少于两个元素的序列也是摆动序列。
//
//例如， [1,7,4,9,2,5] 是一个摆动序列，因为差值 (6,-3,5,-7,3) 是正负交替出现的。相反, [1,4,7,2,5] 和 [1,7,4,5,5]
//不是摆动序列，第一个序列是因为它的前两个差值都是正数，第二个序列是因为它的最后一个差值为零。
//
//给定一个整数序列，返回作为摆动序列的最长子序列的长度。 通过从原始序列中删除一些（也可以不删除）元素来获得子序列，剩下的元素保持其原始顺序。
//
//
//著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

#include <vector>

using namespace std;


//O(n^2)
class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {

        if (nums.empty())
            return 0;

        vector<pair<int, bool>> memo(nums.size(), make_pair(1, true));

        for (int i = 1; i < nums.size(); ++i) {
            for (int j = 0; j < i; ++j) {
                if (nums[j] != nums[i])
                {
                    if (j == 0 and memo[i].first == 1)
                    {

                        memo[i].first = 2;
                        memo[i].second = (nums[i] > nums[0]);
                    }
                    else
                    {
                        if (((nums[i] > nums[j]) xor memo[j].second) and memo[i].first < (memo[j].first + 1) )
                        {
                            memo[i].first = memo[j].first + 1;
                            memo[i].second = !memo[j].second;
                        }
                    }
                }
            }
        }

        int res = 1;

        for (int k = 0; k < nums.size(); ++k) {
            res = max(res, memo[k].first);
        }

        return res;

    }
};


//进行优化，使用两个数组

class Solution2
{
public:
    int wiggleMaxLength(vector<int> & nums)
    {
        if (nums.empty())
            return 0;

        vector<int> up(nums.size(), 1);
        vector<int> down(nums.size(), 1);

        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] > nums[i-1])
            {
                up[i] = down[i-1] + 1;
                down[i] = down[i-1];
            }
            if (nums[i] < nums[i-1])
            {
                up[i] = up[i-1];
                down[i] = up[i-1] + 1;
            }
            if (nums[i] == nums[i-1])
            {
                up[i] = up[i-1];
                down[i] = down[i-1];
            }
        }
        return max(up[nums.size()-1], down[nums.size()-1]);
    }
};

#endif //ALGORITHMS_Q376_WIGGLE_SUBSEQUENCE_H
