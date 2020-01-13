//
// Created by maverick on 2020/1/8.
//

#ifndef ALGORITHMS_Q51_N_QUEENS_H
#define ALGORITHMS_Q51_N_QUEENS_H

//n 皇后问题研究的是如何将 n 个皇后放置在 n×n 的棋盘上，并且使皇后彼此之间不能相互攻击。

#include <string>
#include <vector>
using namespace std;


class Solution {

    //使用三个辅助数组进行冲突检测，
    //col[i] == true即表示第i列已经有其他皇后，dia1表示为左上到右下的对角线，其特点是对角线上的每一个点的x+y相等
    //dia2为右上到左下的对角线，其特点为x-y的值都相等
    //n * n的格子中，对角线共计2 × (2*n - 1)个(两种方向)
    vector<bool> col, dia1, dia2;

    vector<vector<string>> res;

    void generate_board(int n, vector<int> & queen_pos)
    {
        string row;
        for (int j = 0; j < n; ++j) {
            row += '.';
        }
        vector<string> board(n,row);
        for (int i = 0; i < n; ++i) {
            board[i][queen_pos[i]] = 'Q';
        }
        res.push_back(board);
    }

    //尝试把第index个皇后安放在第index行上，queue_pos保存皇后的位置信息
    void put_queue(int n, int index, vector<int> & queen_pos)
    {
        if (index == n)
        {
            generate_board(n, queen_pos);
            return;
        }

        //试图把queue安放在第index行的第i列上
        //核心点在于冲突检测
        for (int i = 0; i < n; ++i) {

            if (!col[i] and !dia1[index+i] and !dia2[index-i+n-1])
            {
                col[i] = true;
                dia1[index+i] = true;
                dia2[index-i+n-1] = true;
                queen_pos.push_back(i);
                put_queue(n, index + 1, queen_pos);
                queen_pos.pop_back();
                col[i] = false;
                dia1[index+i] = false;
                dia2[index-i+n-1] = false;
            }
        }
    }

public:
    vector<vector<string>> solveNQueens(int n) {
        col = vector<bool>(n, false);
        dia1 = vector<bool>(2*n-1, false);
        dia2 = vector<bool>(2*n-1, false);
        res.clear();
        vector<int> queen_pos;
        put_queue(n, 0, queen_pos);
        return res;
    }
};



#endif //ALGORITHMS_Q51_N_QUEENS_H
