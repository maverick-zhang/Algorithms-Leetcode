//
// Created by maverick on 2019/12/31.
//

#ifndef ALGORITHMS_Q20_VALID_PARENTHESES_H
#define ALGORITHMS_Q20_VALID_PARENTHESES_H

#include <string>
#include <stack>

//给定一个只包括 '('，')'，'{'，'}'，'['，']' 的字符串，判断字符串是否有效。
//
//有效字符串需满足：
//
//左括号必须用相同类型的右括号闭合。
//左括号必须以正确的顺序闭合。
//注意空字符串可被认为是有效字符串。

using namespace std;
class Solution {
public:
    bool isValid(string s) {

        stack<char> st;

        for (char ch: s)
        {
            if (ch == '(' or ch == '[' or ch == '{')
                st.push(ch);
            else
            {
                if (st.empty())
                    return false;
                if (ch == ')' and st.top() == '(')
                    st.pop();
                else if (ch == ']' and st.top() == '[')
                    st.pop();
                else if (ch == '}' and st.top() == '{')
                    st.pop();
                else
                    return false;
            }
        }

        return st.empty();
    }
};


#endif //ALGORITHMS_Q20_VALID_PARENTHESES_H
