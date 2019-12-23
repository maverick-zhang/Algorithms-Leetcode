//
// Created by maverick on 2019/12/23.
//

#ifndef ALGORITHMS_Q345_REVERSE_VOWEL_H
#define ALGORITHMS_Q345_REVERSE_VOWEL_H

#include <vector>
#include <string>
using namespace std;


//编写一个函数，以字符串作为输入，反转该字符串中的元音字母。
//
//示例 1:
//
//输入: "hello"
//输出: "holle

class Solution {
    vector<char> vowels {'u', 'o', 'i', 'e', 'a'};
public:
    string reverseVowels(string s) {

        if (s.empty())
            return s;
        int i = 0, j = s.size()-1;
        while (i < j)
        {
            while (!is_vowel(s[i]) and i < j)
                i ++;
            while (!is_vowel(s[j]) and i < j)
                j --;
            if (i == j)
                return s;
            swap(s[i], s[j]);
            i ++;
            j --;
        }
        return s;
    }

    bool is_vowel(const char ch)
    {
        char tem = tolower(ch);
        for (char x: vowels)
            if (x == tem)
                return true;
        return false;

    }
};

#endif //ALGORITHMS_Q345_REVERSE_VOWEL_H
