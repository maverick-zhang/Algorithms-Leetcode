//
// Created by maverick on 2019/12/25.
//

#ifndef ALGORITHMS_Q242_VALID_ANAGRAM_H
#define ALGORITHMS_Q242_VALID_ANAGRAM_H

#include <string>
#include <unordered_map>
using namespace std;

//给定两个字符串 s 和 t ，编写一个函数来判断 t 是否是 s 的字母异位词。
//
//示例 1:
//
//输入: s = "anagram", t = "nagaram"
//输出: true
//

class Solution {
public:
    bool isAnagram(string s, string t) {
        //异位词的含义即为单词字母都相同，只是排列顺序不同
        //解题思路: 使用unorder_map，键为字符串s中的字母，值为字母出现的次数

        if (s.size() != t.size())
            return false;

        unordered_map<char, int> record;
        for (auto ch: s)
            record[ch] ++;

        for (auto ch: t)
        {
            if (record.find(ch) == record.end())
                return false;
            if (record[ch] <= 0)
                return false;
            record[ch] --;
        }

        return true;
    }
};



#endif //ALGORITHMS_Q242_VALID_ANAGRAM_H
