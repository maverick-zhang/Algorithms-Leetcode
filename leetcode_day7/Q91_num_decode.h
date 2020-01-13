//
// Created by maverick on 2020/1/9.
//

#ifndef ALGORITHMS_Q91_NUM_DECODE_H
#define ALGORITHMS_Q91_NUM_DECODE_H

#include <vector>
#include <string>
using namespace std;

//一条包含字母 A-Z 的消息通过以下方式进行了编码：
//
//'A' -> 1
//'B' -> 2
//...
//'Z' -> 26
//给定一个只包含数字的非空字符串，请计算解码方法的总数


//题目真的真的垃圾
//
//class Solution {
//private:
//    vector<unsigned long long> memo;
//    bool is_verified(char a, char b)
//    {
//        return ((a - '0') * 10 + (b - '0')) <= 26;
//    }
//public:
//    int numDecodings(string s) {
//        memo = vector<unsigned long long> (s.size(), -1);
//        int len = s.size();
//        if (len == 1)
//            return s[0] != '0';
//
//        memo[0] = 1;
//
//        for (int i = 1; i < len; ++i) {
//
//            if (s[len-1-i] == '0')
//            {
//                if (i== len - 1 or !(s[len - 2 -i] == '1' or s[len-2-i] == '2') or s[len - i] == '0')
//                    return 0;
//                memo[i+1] = memo[i] = memo[i - 1];
//                if (i+2 < len)
//                {
//                    memo[i+2] = memo[i+1];
//                    i++;
//                }
//                i ++;
//                continue;
//            }
//
//            if (i == 1) {
//                if (s[len - 1] == '0') {
//                    if (s[len - 2] - '0' <= 2) {
//                        memo[1] = 1;
//                        if (len > 2)
//                        {
//                            if (s[len -3] != '0')
//                            {
//                                memo[2] = 1;
//                                i ++;
//                            }
//                        }
//                        continue;
//                    } else
//                        return 0;
//                }
//                else
//                {
//                    if (is_verified(s[len-2], s[len-1]))
//                        memo[1] = 2;
//                    else
//                        memo[1] = 1;
//                }
//                continue;
//            }
//
//            memo[i] = memo[i - 1];
//
//
//            if (is_verified(s[len - 1 - i], s[len -i]))
//            {
//                memo[i] += memo[i - 2];
//            }
//        }
//        return memo[len - 1];
//
//    }
//};

class Solution {
public:
    int numDecodings(string s) {
        int cnt = 0;
        if(s.size() == 0 || (s.size() == 1 && s[0] == '0')) return 0;
        if(s.size() == 1) return 1;
        vector<int> dp(s.size() + 1, 0);
        dp[0] = 1;
        for(int i = 0; i < s.size(); ++i){
            dp[i+1] = s[i] == '0' ? 0 : dp[i];
            if(i > 0 && (s[i-1] == '1' || (s[i-1] == '2' && s[i] <= '6'))){
                dp[i+1] += dp[i-1];
            }
        }
        return dp.back();
    }

};

#endif //ALGORITHMS_Q91_NUM_DECODE_H
