//
// Created by maverick on 2019/12/25.
//

#ifndef ALGORITHMS_Q290_WORD_PATTERN_H
#define ALGORITHMS_Q290_WORD_PATTERN_H

#include <string>
#include <cstring>
#include <unordered_set>
#include <vector>
#include <unordered_map>
//给定一种规律 pattern 和一个字符串 str ，判断 str 是否遵循相同的规律。
//
//这里的 遵循 指完全匹配，例如， pattern 里的每个字母和字符串 str 中的每个非空单词之间存在着双向连接的对应规律。
//
//示例1:
//
//输入: pattern = "abba", str = "dog cat cat dog"
//输出: true
//示例 2:
//
//输入:pattern = "abba", str = "dog cat cat fish"
//输出: false
//示例 3:
//
//输入: pattern = "aaaa", str = "dog cat cat dog"
//输出: false
//示例 4:
//
//输入: pattern = "abba", str = "dog dog dog dog"
//输出: false

using namespace std;

class Solution {
public:

    vector<string> split(string  str)
    {
        vector<string> res;
        str += " ";
        int i = 0, pos = 0;
        string temp;
        while (i < str.size())
        {
            pos = str.find(' ', i);

            temp = str.substr(i, pos-i);
            res.push_back(temp);
            i = pos + 1;
        }
        return res;
    }
    bool wordPattern(string pattern, string str) {


        vector<string> words = split(str);

        if (pattern.size() != words.size())
            return false;

        unordered_map<char, string> record1;
        unordered_set<string> record2;



        string temp;
        for (int j = 0; j<pattern.size();j++)
        {
            if (record1.find(pattern[j]) == record1.end())
            {
                if (record2.find(words[j]) != record2.end())
                    return false;
                record1[pattern[j]] = words[j];
                record2.insert(words[j]);
            }
            else
            {
                if (record1[pattern[j]] != words[j])
                    return false;
            }
        }

        return true;

    }
};

#endif //ALGORITHMS_Q290_WORD_PATTERN_H
