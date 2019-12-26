//
// Created by maverick on 2019/12/23.
//

#ifndef ALGORITHMS_Q3_LONGEST_SUBSTRING_WITHOUT_REPEAT_CHAR_H
#define ALGORITHMS_Q3_LONGEST_SUBSTRING_WITHOUT_REPEAT_CHAR_H

#include <string>
using namespace std;

//给定一个字符串，请你找出其中不含有重复字符的 最长子串 的长度。
//
//示例 1:
//
//输入: "abcabcbb"
//输出: 3
//解释: 因为无重复字符的最长子串是 "abc"，所以其长度为 3。

class Solution {
public:
    int lengthOfLongestSubstring(string s) {

        //使用一个滑动窗口[l, r]代表一个不包含重复字符的子串,r端不断向前直到出现重复的字符，此时记录最大值
        //左端口持续向右移动直到没有相同的字符，反复操作直到l到达最右端
        //判断是否有相同的字符，创建一个bool数组，数组的下标对应字符的ascii码,为1时代表子串包含该字符

        if (s.empty())
            return 0;

        bool is_repeated[256] {false};

        int l = 0, r = -1;
        int len = 1;

        while (l < s.size())
        {
            if ( r + 1 < s.size() and !is_repeated[s[r+1]])
                is_repeated[s[++r]] = true;
            else
                is_repeated[s[l++]] = false;

            if (r-l+1 > len)
                len = r -l + 1;
        }

        return len;


    }
};

#endif //ALGORITHMS_Q3_LONGEST_SUBSTRING_WITHOUT_REPEAT_CHAR_H
