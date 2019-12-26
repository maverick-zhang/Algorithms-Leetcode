//
// Created by maverick on 2019/12/25.
//

#ifndef ALGORITHMS_Q454_FOUR_SUM2_H
#define ALGORITHMS_Q454_FOUR_SUM2_H

#include <vector>
#include <unordered_map>

using namespace std;

//给定四个包含整数的数组列表 A , B , C , D ,计算有多少个元组 (i, j, k, l) ，使得 A[i] + B[j] + C[k] + D[l] = 0。
//
//为了使问题简单化，所有的 A, B, C, D 具有相同的长度 N，且 0 ≤ N ≤ 500 。


class Solution {
public:

    //算法复杂度O(n^2)
    //使用一个字典，把A+B的所有可能放入字典，值为(A+B)出现的次数
    //在循环遍历C,D把 查找所有C，D的组合的补是否出现在字典中

    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {


        unordered_map<int, int> record;
        int res = 0;
        for (int i = 0; i < A.size() ; ++i) {
            for (int j = 0; j < B.size(); ++j) {
                record[A[i] + B[j]] ++;
            }
        }

        for (int k = 0; k < C.size() ; ++k) {
            for (int i = 0; i < D.size(); ++i) {
                if (record.find(0-C[k]-D[i]) != record.end())
                    res += record[0 - C[k] - D[i]];
            }
        }

        return res;

    }
};

#endif //ALGORITHMS_Q454_FOUR_SUM2_H
