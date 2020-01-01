//
// Created by maverick on 2019/12/31.
//

#ifndef ALGORITHMS_Q150_REVERSE_POLISH_H
#define ALGORITHMS_Q150_REVERSE_POLISH_H

#include <vector>
#include <string>
#include <stack>

//根据逆波兰表示法，求表达式的值。
//
//有效的运算符包括 +, -, *, / 。每个运算对象可以是整数，也可以是另一个逆波兰表达式。
//
//输入: ["2", "1", "+", "3", "*"]
//输出: 9
//解释: ((2 + 1) * 3) = 9

using std::vector;
using std::string;
using std::stack;
using std::stoi;
using std::to_string;


class Solution {

public:
    int evalRPN(vector<string>& tokens) {

        stack<int> st;
        int num1;
        int num2;
        char calc;
        for (string & s: tokens)
        {
            if (isdigit(s[0]))
                st.push(stoi(s));
            else if (s[0] == '-' and s.size() > 1 and isdigit(s[1]))
                st.push(stoi(s));
            else
            {
                calc = s[0];
                num2 = st.top();
                st.pop();
                num1 = st.top();
                st.pop();
                int temp;
                if (calc == '+')
                    temp = num1 + num2;
                else if (calc == '-')
                    temp = num1 - num2;
                else if (calc == '*')
                    temp = num1 * num2;
                else
                    temp = num1 / num2;
                st.push(temp);
            }
        }
        return st.top();
    }
};

#endif //ALGORITHMS_Q150_REVERSE_POLISH_H
