//
// Created by maverick on 2020/1/1.
//

#ifndef ALGORITHMS_Q279_NUM_SQUARES_H
#define ALGORITHMS_Q279_NUM_SQUARES_H

//给定正整数 n，找到若干个完全平方数（比如 1, 4, 9, 16, ...）使得它们的和等于 n。你需要让组成和的完全平方数的个数最少。
//
//示例 1:
//
//输入: n = 12
//输出: 3
//解释: 12 = 4 + 4 + 4.

#include <queue>
#include <unordered_set>
using namespace std;

class Solution {
public:

    //把每一个n-k作为图上的节点(k为一个完全平方数或几个完全平方数之和)
    //以n为图的起始点，遍历每一个小于等于n的完全平方数，把差添加到图中，步数加一广度优先遍历图中其他的节点进行相同的操作，直到找到值为0的节点
    int numSquares(int n) {

        queue<pair<int, int>> que;

        que.push(make_pair(n, 0));
        unordered_set<int> map_node;
        map_node.insert(n);

        int step;
        while (!que.empty())
        {
            step = que.front().second;
            n = que.front().first;
            for (int i = 1; i * i <= n; ++i) {

                int next_node = n - i * i;

                if (next_node == 0)
                    return step + 1;
                if (map_node.find(next_node) == map_node.end())
                {
                    map_node.insert(next_node);
                    que.push(make_pair(next_node, step + 1));
                }
            }
            que.pop();
        }
        throw invalid_argument("no solution");
    }
};


#endif //ALGORITHMS_Q279_NUM_SQUARES_H
