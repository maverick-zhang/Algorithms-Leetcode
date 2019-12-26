//
// Created by maverick on 2019/12/25.
//

#ifndef ALGORITHMS_Q451_SORT_CHARACTERS_BY_FREQUENCY_H
#define ALGORITHMS_Q451_SORT_CHARACTERS_BY_FREQUENCY_H

#include <string>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

//给定一个字符串，请将字符串里的字符按照出现的频率降序排列。
//
//示例 1:
//
//输入:
//"tree"
//
//输出:
//"eert"
//
//解释:
//'e'出现两次，'r'和't'都只出现一次。
//因此'e'必须出现在'r'和't'之前。此外，"eetr"也是一个有效的答案。



class Solution {

private:
    static bool cmp(pair<char, int> & p1, pair<char, int> & p2)
    {
        return p1.second > p2.second;
    }
public:

    //时间复杂度为O(nlogn)
    //map不可以直接进行按照value进行排序,默认进行key排序,因为内部是一颗平衡二叉树
    //如果需要自定义key的排序map<key, value, cmp_func>

    string frequencySort(string s) {

        map<char, int> record;

        for(char ch: s)
            record[ch] ++;

        vector<pair<char, int>> rec_list(record.begin(), record.end());

        sort(rec_list.begin(), rec_list.end(), cmp);

        string res;

        for (int i = 0; i < rec_list.size(); ++i) {
            while (rec_list[i].second > 0)
            {
                res += rec_list[i].first;
                rec_list[i].second --;
            }
        }

        return res;
    }
};



#endif //ALGORITHMS_Q451_SORT_CHARACTERS_BY_FREQUENCY_H
