//
// Created by maverick on 2019/12/31.
//

#ifndef ALGORITHMS_Q71_SIMPLIFY_PATH_H
#define ALGORITHMS_Q71_SIMPLIFY_PATH_H

#include <string>
#include <stack>

//以 Unix 风格给出一个文件的绝对路径，你需要简化它。或者换句话说，将其转换为规范路径。
//
//在 Unix 风格的文件系统中，一个点（.）表示当前目录本身；此外，两个点 （..） 表示将目录切换到上一级（指向父目录）；两者都可以是复杂相对路径的组成部分。
//
//请注意，返回的规范路径必须始终以斜杠 / 开头，并且两个目录名之间必须只有一个斜杠 /。最后一个目录名（如果存在）不能以 / 结尾。此外，规范路径必须是表示绝对路径的最短字符串。
using namespace std;

class Solution {
public:
    string simplifyPath(string path) {
        stack<char> st;
        for (int i = 0; i < path.size(); ++i)
        {

            if (st.empty()) {
                st.push(path[i]);
                continue;
            }
            if (path[i] == '/' and st.top() == '/')
                continue;
            else if (path[i] == '/' and st.top() == '.') {
                st.pop();
                if (st.top() == '.')
                {
                    st.push('.');
                    st.push(path[i]);
                }
                continue;
            } else if (path[i] == '/') {
                st.push(path[i]);
                continue;
            }
            if (path[i] == '.' and st.top() != '.') {
                st.push(path[i]);
                continue;
            } else if (path[i] == '.' and st.top() == '.') {

                if (i + 1 < path.size() and path[i + 1] != '/') {
                    st.push(path[i]);
                    st.push(path[i + 1]);
                    i++;
                    continue;
                }
                st.pop();
                if (st.size() == 1)
                    continue;
                st.pop();
                while (st.top() != '/')
                    st.pop();
                continue;
            }

            st.push(path[i]);
        }

        if (st.size() > 1 and st.top() == '/')
            st.pop();

        if (st.top() == '.')
        {
            st.pop();
            if (st.top() == '.')
            {
                st.push('.');
            }
        }

        if (st.size() > 1 and st.top() == '/')
            st.pop();

        stack<char> res_st;
        while (!st.empty()) {
            res_st.push(st.top());
            st.pop();
        }
        string res;
        while (!res_st.empty()) {
            res += res_st.top();
            res_st.pop();
        }

        return res;
    }
};

#endif //ALGORITHMS_Q71_SIMPLIFY_PATH_H
