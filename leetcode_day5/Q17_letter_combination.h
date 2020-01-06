//
// Created by maverick on 2020/1/6.
//

#ifndef ALGORITHMS_Q17_LETTER_COMBINATION_H
#define ALGORITHMS_Q17_LETTER_COMBINATION_H

#include <string>
#include <vector>

using namespace std;

//给定一个仅包含数字 2-9 的字符串，返回所有它能表示的字母组合。
//
//给出数字到字母的映射如下（与电话按键相同）。注意 1 不对应任何字母。

class Solution {
private:

    vector<string> res;


    string number_chars[10] {
      " ",      //0
      "",       //1
      "abc",    //2
      "def",    //3
      "ghi",    //4
      "jkl",    //5
      "mno",    //6
      "pqrs",   //7
      "tuv",    //8
      "wxyz",   //9
    };

    void combine(const string & digits, string * str_ar, int i,  string s)
    {
        if (i == digits.size())
        {
            res.push_back(s);
            return;
        }
        string digit_chars = number_chars[digits[i] - '0'];
        for (char digit_char : digit_chars)
            combine(digits, str_ar, i + 1, s+digit_char);
    }

public:

    //使用递归和回溯的方法，组合所有的字母
    //
    vector<string> letterCombinations(string digits) {

      if (digits.empty())
          return res;

      combine(digits, number_chars, 0, "");

      return res;
    }
};

#endif //ALGORITHMS_Q17_LETTER_COMBINATION_H
