//
// Created by maverick on 2020/1/6.
//

#ifndef ALGORITHMS_Q131_PARTITION_PALINDROME_H
#define ALGORITHMS_Q131_PARTITION_PALINDROME_H

//给定一个字符串 s，将 s 分割成一些子串，使每个子串都是回文串。
//
//返回 s 所有可能的分割方案。

//输入: "aab"
//输出:
//[
//["aa","b"],
//["a","a","b"]
//]

#include <vector>
#include <string>

using namespace std;

//回溯法

class Solution {

private:

    bool is_palindrome(const string & str)
    {
        int i = 0, j = str.size() - 1;
        while (i < j)
        {
            if (str[i] != str[j])
                return false;
            i ++;
            j --;
        }
        return true;
    }


    vector<vector<string>> res;

    void __partition(const string & s, int index, vector<string> & vt)
    {
        if (index == s.size())
        {
            res.push_back(vt);
            return;
        }

        for (int i = 1; i + index <= s.size(); ++i) {
            string temp;
            for (int j = 0; j < i; ++j)
                temp += s[index + j];
            if (is_palindrome(temp))
            {
                vector<string> new_vt(vt);
                new_vt.push_back(temp);
                __partition(s, index + i, new_vt);
            }
        }
    }

public:
    vector<vector<string>> partition(string s) {

        vector<string> vt;
        __partition(s, 0, vt);

        return res;
    }
};

#endif //ALGORITHMS_Q131_PARTITION_PALINDROME_H
