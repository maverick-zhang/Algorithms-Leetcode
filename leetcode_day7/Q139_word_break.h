//
// Created by maverick on 2020/1/10.
//

#ifndef ALGORITHMS_Q139_WORD_BREAK_H
#define ALGORITHMS_Q139_WORD_BREAK_H

//给定一个非空字符串 s 和一个包含非空单词列表的字典 wordDict，判定 s 是否可以被空格拆分为一个或多个在字典中出现的单词。
//
//说明：
//
//拆分时可以重复使用字典中的单词。
//你可以假设字典中没有重复的单词。
//示例 1：
//
//输入: s = "leetcode", wordDict = ["leet", "code"]
//输出: true
//解释: 返回 true 因为 "leetcode" 可以被拆分成 "leet code"。

#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>
using namespace std;


//背包问题的变种
//单词s每次只能从头或者尾部切去一部分
//s[0:i]的部分能否被切去

class Solution {

    unordered_map<string, string> memo;

    string word_break(string & s1, string & s2)
    {
        string key = s1+":"+s2;
        if (memo.find(key)!= memo.end())
            return memo[key];
        //只从头部尝试切割
        for (int i = 0; i < s2.size(); ++i) {
            if (i >= s1.size() or s1[i] != s2[i])
            {
                memo[key] = s1;
                return s1;
            }
        }

        string remain(s1.begin()+s2.size(), s1.end());
        memo[key] = remain;
        return remain;
    }

public:
    bool wordBreak(string s, vector<string>& wordDict) {

        //使用第i个词切割
        for (int i = 0; i < wordDict.size(); ++i) {
            string temp = word_break(s, wordDict[i]);
            if (temp.empty())
                return true;
            bool found;
            if (temp != s and wordBreak(temp, wordDict))
                return true;
        }
        return false;
    }
};


//动态规划
class Solution2
{
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        //memo[i]表示s[:i](前闭后开)的字符串是否可以被分解
        vector<bool> memo(s.size()+1, false);
        unordered_set<string> m(wordDict.begin(), wordDict.end());
        memo[0] = true;
        for (int i = 1; i <= s.size(); ++i){
            for (int j = 0; j < i; ++j){
                if (memo[j] && m.find(s.substr(j, i-j)) != m.end()){
                    memo[i] = true;
                    break;
                }
            }
        }
        return memo[s.size()];
    }
};


#endif //ALGORITHMS_Q139_WORD_BREAK_H
