//
// Created by maverick on 2019/12/25.
//

#ifndef ALGORITHMS_Q205_ISOMORPHIC_STRING_H
#define ALGORITHMS_Q205_ISOMORPHIC_STRING_H

#include <string>
#include <unordered_map>
#include <unordered_set>
using namespace std;


//给定两个字符串 s 和 t，判断它们是否是同构的。
//
//如果 s 中的字符可以被替换得到 t ，那么这两个字符串是同构的。
//
//所有出现的字符都必须用另一个字符替换，同时保留字符的顺序。两个字符不能映射到同一个字符上，但字符可以映射自己本身。
//
//示例 1:
//
//输入: s = "egg", t = "add"
//输出: true

class Solution {
public:
    bool isIsomorphic(string s, string t) {

        if (s.size() != t.size())
            return false;

        unordered_map<char, char> record1;
        unordered_set<char> record2;

        for (int i = 0; i < s.size(); i++)
        {
            if (record1.find(s[i]) == record1.end())
            {
                if (record2.find(t[i]) != record2.end())
                    return false;
                record1[s[i]] = t[i];
                record2.insert(t[i]);

            }
            else
            {
//                if (record2.find(t[i]) == record2.end())
//                    return false;
                if (record1[s[i]] != t[i])
                    return false;
            }
        }

        return true;

    }
};


#endif //ALGORITHMS_Q205_ISOMORPHIC_STRING_H
