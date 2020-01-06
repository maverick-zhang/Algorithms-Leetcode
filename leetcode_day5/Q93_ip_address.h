//
// Created by maverick on 2020/1/6.
//

#ifndef ALGORITHMS_Q93_IP_ADDRESS_H
#define ALGORITHMS_Q93_IP_ADDRESS_H

#include <vector>
#include <string>

using namespace std;

//给定一个只包含数字的字符串，复原它并返回所有可能的 IP 地址格式。
//
//示例:
//
//输入: "25525511135"
//输出: ["255.255.11.135", "255.255.111.35"]


//ip地址的每一个区间都是0-255，因此每一间隔都有可能是1位数，两位数或者三位数
//因此需要分三类可能进行递归
//每次递归都假设前面的组成的ip已确认合法,当前的递归中，对剩余的数字分三种进行组合
class Solution {
    vector<string> res;

    //index表示剩余的数字当中，第一个的索引，i表示当前为ip的第几个字段
    void converter(const string & s, string ip, int index, int i)
    {

        if (i == 5 and index == s.size())
        {
            res.push_back(ip);
            return;
        }

        if (index >= s.size() or i == 5)
            return;

        if (i != 1)
            ip += ".";

        converter(s, ip + s[index], index+1, i+1);
        if (s[index] != '0' and index + 1 < s.size())
            converter(s, ip + s[index] + s[index + 1], index + 2, i + 1);
        if (s[index] != '0' and index + 2 < s.size())
        {
            int num = 0;
            for (int j = index; j < index + 3; ++j)
                num = num * 10 + s[j] - '0';
            if (num > 255)
                return;
            converter(s, ip + s[index] + s[index+1] + s[index+2], index + 3, i + 1);
        }

    }

public:
    vector<string> restoreIpAddresses(string s) {

        converter(s, "", 0, 1);
        return res;
    }
};

#endif //ALGORITHMS_Q93_IP_ADDRESS_H
