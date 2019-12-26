//
// Created by maverick on 2019/12/23.
//

#ifndef ALGORITHMS_Q76_MINIMUM_WINDOW_SUBSTRING_H
#define ALGORITHMS_Q76_MINIMUM_WINDOW_SUBSTRING_H

#include <string>
#include <unordered_map>
#include <vector>
using namespace std;


//给你一个字符串 S、一个字符串 T，请在字符串 S 里面找出：包含 T 所有字母的最小子串。
//
//示例：
//
//输入: S = "ADOBECODEBANC", T = "ABC"
//输出: "BANC"
//说明：
//
//如果 S 中不存这样的子串，则返回空字符串 ""。
//如果 S 中存在这样的子串，我们保证它是唯一的答案。
//class Solution {
//public:
//
//    bool is_contain_all(unordered_map<char, int> & is_contain, unordered_map<char, int> & chars_t, const string & t)
//    {
//        for (int i = 0; i < 128; ++i) {
//            if (chars_t.count(i))
//            {
//                if (chars_t[i] > is_contain[i])
//                    return false;
//            }
//        }
//
//        return true;
//    }
//
//    string minWindow(string s, string t) {
//
//        string res;
//
//        if (s.empty())
//            return res;
//
//        unordered_map<char, int> chars_of_t;
//        for (char ch: t)
//            chars_of_t[ch] ++;
//
//        vector<pair<int, char >> filtered_s;
//
//        for (int i = 0; i < s.size(); ++i) {
//            if (chars_of_t.count(s[i]))
//                filtered_s.emplace_back(pair<int, char>(i, s[i]));
//        }
//
//
//
//        unordered_map<char, int > is_contain;
//
//
//
//
//        int l = 0, r = -1;
//        int res_l = 0, res_r = -1;
//        while (l < filtered_s.size())
//        {
//            if (r+1 < filtered_s.size() and !is_contain_all(is_contain, chars_of_t, t))
//                is_contain[filtered_s[++r].second] ++;
//            else
//                is_contain[filtered_s[l++].second] --;
//
//            if (is_contain_all(is_contain, chars_of_t, t)
//                and (res_r == -1 or (res_r - res_l > filtered_s[r].first - filtered_s[l].first)))
//            {
//                res_r = filtered_s[r].first;
//                res_l = filtered_s[l].first;
//            }
//        }
//        if (res_r == -1)
//            return res;
//        string res2(s, res_l, res_r - res_l + 1);
//        return res2;
//    }
//};


class Solution {
public:
    string minWindow(string s, string t)
    {
        array<int, 128>chars_count_t {0};
        array<int, 128>chars_count_s {0};

        for (auto ch : t)
            ++chars_count_t[ch];
        for (auto ch : s)
            ++chars_count_s[ch];

        //判断是否存在解
        for (int i = 0; i < 128; ++i)
            if (chars_count_s[i] < chars_count_t[i])
                return string("");

        int start = 0, end = s.size()-1;

        //对s从右向左遍历找到第一个窗口
        for (; chars_count_s[s[end]] > chars_count_t[s[end]]; --chars_count_s[s[end]],--end);

        int len = end - start + 1;
        for (int l = 0, j = end;;++l)
        {
            //左端向右滑动直到s[l]字符只有一个，[l, r]仍是符合的
            for (; chars_count_s[s[l]] > chars_count_t[s[l]];--chars_count_s[s[l]],++l);
            if (j - l + 1 < len)
            {
                len = j - l + 1;
                start = l;
                end = j;
            }

            //右端向右滑动直到找到一个字符s[r] == s[l]
            for (j = j + 1; j < s.size() && s[j] != s[l]; ++chars_count_s[s[j]],++j);
            if (j == s.size())break;
        }
        string res;
        for (int i = start; i <= end; ++i)
        {
            res.push_back(s[i]);
        }
        return res;
    }
};


#endif //ALGORITHMS_Q76_MINIMUM_WINDOW_SUBSTRING_H
