//
// Created by maverick on 2019/12/23.
//

#ifndef ALGORITHMS_Q125_VALID_PALINDROME_H
#define ALGORITHMS_Q125_VALID_PALINDROME_H

#include <vector>
#include <string>

using namespace std;
//给定一个字符串，验证它是否是回文串，只考虑字母和数字字符，可以忽略字母的大小写。
//
//说明：本题中，我们将空字符串定义为有效的回文串。
//
//示例 1:
//
//输入: "A man, a plan, a canal: Panama"
//输出: true


//注意边界问题

class Solution {
public:
    bool isPalindrome(string s) {

        if (s.empty())
            return true;
        int i = 0, j = s.size() - 1;
        while (i <= j)
        {
            while (!isalnum(s[i]) and i < j)
                i ++;
            while (!isalnum(s[j]) and j > i)
                j --;
            if (i == j and !isalnum(s[i]))
                return true;
            if (tolower(s[i]) != tolower(s[j]))
                return false;
            i ++;
            j --;
        }

        return true;


    }
};

#endif //ALGORITHMS_Q125_VALID_PALINDROME_H
