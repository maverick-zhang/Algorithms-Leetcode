//
// Created by maverick on 2019/12/23.
//

#ifndef ALGORITHMS_Q438_FIND_ANAGRAMS_H
#define ALGORITHMS_Q438_FIND_ANAGRAMS_H
//给定一个字符串 s 和一个非空字符串 p，找到 s 中所有是 p 的字母异位词的子串，返回这些子串的起始索引。
//
//字符串只包含小写英文字母，并且字符串 s 和 p 的长度都不超过 20100。

#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        unordered_map<char, int> ch_map;
        vector<int> res;
        for (char ch: p)
            ch_map[ch] += 1;
        // [l, r]代表一个窗口，其窗口内的所有字符都为p中的字符
        int l = 0, r = -1;
        bool found_start = false;
        while (r+1 < s.size()){

            if (!found_start)
            {
                while (!found_start and l < s.size()){
                    if (ch_map.find(s[l]) != ch_map.end())
                        found_start = true;
                    else
                        l ++;
                }
                ch_map[s[l]] -= 1;
                r = l;
            }

            if (p.size() == 1 and l < s.size())
            {
                res.push_back(l);
                l ++;
                found_start = false;
                continue;
            }

            if (r+1 >= s.size())
                break;

            if (ch_map.find(s[r+1]) != ch_map.end() and ch_map[s[r+1]] > 0){

                ch_map[s[r+1]] --;
                r ++;
            }
            else{
                ch_map[s[l]] ++;
                l ++;
                if (l == r+1)
                    found_start = false;
            }
            if (r-l + 1 == p.size())
                res.push_back(l);

        }
        return res;
    }
};

//TODO
#endif //ALGORITHMS_Q438_FIND_ANAGRAMS_H
