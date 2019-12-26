//
// Created by maverick on 2019/12/25.
//

#ifndef ALGORITHMS_Q350_INTERSECTION_OF_TWO_ARRAYS2_H
#define ALGORITHMS_Q350_INTERSECTION_OF_TWO_ARRAYS2_H

#include <map>
#include <vector>

using namespace std;

//给定两个数组，编写一个函数来计算它们的交集。
//
//示例 1:
//
//输入: nums1 = [1,2,2,1], nums2 = [2,2]
//输出: [2,2]

class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {

        map<int, int> s1;
        vector<int> res;

        for (int i = 0; i < nums1.size(); ++i) {
            s1[nums1[i]] ++;
        }

        for (int j = 0; j < nums2.size(); ++j) {
            if (s1[nums2[j]] > 0)
            {
                s1[nums2[j]] --;
                res.push_back(nums2[j]);
            }
        }

        return res;
    }
};

#endif //ALGORITHMS_Q350_INTERSECTION_OF_TWO_ARRAYS2_H
