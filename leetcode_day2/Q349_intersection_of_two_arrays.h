//
// Created by maverick on 2019/12/25.
//

#ifndef ALGORITHMS_Q349_INTERSECTION_OF_TWO_ARRAYS_H
#define ALGORITHMS_Q349_INTERSECTION_OF_TWO_ARRAYS_H

#include <vector>
#include <set>
using namespace std;

//给定两个数组，编写一个函数来计算它们的交集。
//
//示例 1:
//
//输入: nums1 = [1,2,2,1], nums2 = [2,2]
//输出: [2]


class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {

        set<int> s1(nums1.begin(), nums1.end());
        set<int> res;

        for (int i = 0; i < nums2.size(); ++i) {
            if (s1.find(nums2[i]) != s1.end())
                res.insert(nums2[i]);

        }

        return vector<int> (res.begin(), res.end());

    }
};

#endif //ALGORITHMS_Q349_INTERSECTION_OF_TWO_ARRAYS_H
