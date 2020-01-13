//
// Created by maverick on 2020/1/10.
//

#ifndef ALGORITHMS_Q474_ONE_AND_ZEROS_H
#define ALGORITHMS_Q474_ONE_AND_ZEROS_H

//在计算机界中，我们总是追求用有限的资源获取最大的收益。
//
//现在，假设你分别支配着 m 个 0 和 n 个 1。另外，还有一个仅包含 0 和 1 字符串的数组。
//
//你的任务是使用给定的 m 个 0 和 n 个 1 ，找到能拼出存在于数组中的字符串的最大数量。每个 0 和 1 至多被使用一次。
//
//注意:
//
//给定 0 和 1 的数量都不会超过 100。
//给定字符串数组的长度不会超过 600。
//示例 1:
//
//输入: Array = {"10", "0001", "111001", "1", "0"}, m = 5, n = 3
//输出: 4
//
//解释: 总共 4 个字符串可以通过 5 个 0 和 3 个 1 拼出，即 "10","0001","1","0" 。

#include <vector>
#include <string>

using namespace std;

//可以理解为背包问题

//递归求解
//
class Solution {

    vector<vector<vector<int>>> memo;

    vector<pair<int, int>> nums_of_char;

    //[0, index]之间能够取得最大的收益
    int max_form(vector<string> & strs, int index, int m, int n) {
        if (index < 0)
            return 0;
        if (memo[index][m][n] != -1)
            return memo[index][m][n];

        int new_m = m - nums_of_char[index].first;
        int new_n = n - nums_of_char[index].second;

        if (new_m < 0 or new_n < 0)
        {
            memo[index][m][n] = max_form(strs, index - 1, m ,n);
            return memo[index][m][n];
        }

        memo[index][m][n] = max(max_form(strs, index -1, new_m, new_n) + 1, max_form(strs, index-1, m, n));
        return memo[index][m][n];
    }


public:
    int findMaxForm(vector<string>& strs, int m, int n) {


        for (int i = 0; i < strs.size(); ++i) {
            int num_1 = 0, num_0 = 0;
            for (int j = 0; j < strs[i].size(); ++j) {
                if (strs[i][j] == '1')
                    num_1 ++;
                else
                    num_0 ++;
            }
            nums_of_char.push_back(make_pair(num_0, num_1));
        }

        memo = vector<vector<vector<int>>> (strs.size(), vector<vector<int>>(m+1, vector<int>(n+1, -1)));

        return max_form(strs, strs.size()-1, m, n);

    }
};

//动态规划

class Solution2
{
    vector<vector<int>> memo;

    vector<pair<int, int>> nums_of_char;
public:

    int findMaxForm(vector<string>& strs, int m, int n)
    {
        for (int i = 0; i < strs.size(); ++i) {
            int num_1 = 0, num_0 = 0;
            for (int j = 0; j < strs[i].size(); ++j) {
                if (strs[i][j] == '1')
                    num_1 ++;
                else
                    num_0 ++;
            }
            nums_of_char.push_back(make_pair(num_0, num_1));
        }

        memo = vector<vector<int>> (m+1, vector<int>(n+1, 0));

        //只包含一个物品
        for (int i = nums_of_char[0].first; i <= m ; ++i) {
            for (int j = nums_of_char[0].second; j <= n ; ++j) {
                memo[i][j] = 1;
            }
        }

        //包含多个物品
        //空间进行了压缩
        for (int k = 1; k < strs.size() ; ++k) {
            for (int i = m; i >= nums_of_char[k].first ; --i) {
                for (int j = n; j >= nums_of_char[k].second ; --j) {
                    memo[i][j] = max(memo[i][j], 1 + memo[i-nums_of_char[k].first][j-nums_of_char[k].second]);
                }
            }
        }
        return memo[m][n];
    }
};

#endif //ALGORITHMS_Q474_ONE_AND_ZEROS_H
