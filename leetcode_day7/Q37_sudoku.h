//
// Created by maverick on 2020/1/8.
//

#ifndef ALGORITHMS_Q37_SUDOKU_H
#define ALGORITHMS_Q37_SUDOKU_H

//编写一个程序，通过已填充的空格来解决数独问题。
//
//一个数独的解法需遵循如下规则：
//
//数字 1-9 在每一行只能出现一次。
//数字 1-9 在每一列只能出现一次。
//数字 1-9 在每一个以粗实线分隔的 3x3 宫内只能出现一次。
//空白格用 '.' 表示。

#include <vector>
using namespace std;

class Solution {

    //使用三个辅助数组记录每行每列中已经使用的数字
    vector<vector<bool>> row_used;
    vector<vector<bool>> col_used;
    vector<vector<vector<bool>>> square_used;

    bool found_solve;


    //尝试把num(1-9)放入board[row][col]列中
    void put_number(int row, int col, vector<vector<char>> & board)
    {

        if (row == 9 or found_solve)
        {
            found_solve = true;
            return;
        }

        if (col < 9 and board[row][col] == '.')
        {

            for (int num = 1; num < 10; ++num) {
                if (!row_used[row][num - 1] and !col_used[col][num - 1] and !square_used[row/3][col/3][num-1])
                {

                    row_used[row][num-1] = true;
                    col_used[col][num - 1] = true;
                    square_used[row/3][col/3][num-1] = true;
                    board[row][col] = num + '0';
                    put_number(row, col + 1, board);
                    if (found_solve)
                        return;
                    row_used[row][num-1] = false;
                    col_used[col][num - 1] = false;
                    square_used[row/3][col/3][num-1] = false;
                    board[row][col] = '.';
                }
            }
        }
        else
        {
            if (col == 9)
                put_number(row + 1, 0, board);
            else
                put_number(row, col + 1, board);
        }
    }

public:
    void solveSudoku(vector<vector<char>>& board) {

        row_used = vector<vector<bool>> (9, vector<bool>(9, false));
        col_used = vector<vector<bool>> (9, vector<bool>(9, false));
        square_used = vector<vector<vector<bool>>>(3, vector<vector<bool>>(3, vector<bool>(9, false)));
        found_solve = false;


        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
                if (board[i][j] != '.')
                {
                    int num = board[i][j] - '0';
                    row_used[i][num - 1] = true;
                    col_used[j][num - 1] = true;
                    square_used[i/3][j/3][num-1] = true;
                }
            }
        }
        put_number(0, 0, board);
    }
};



#endif //ALGORITHMS_Q37_SUDOKU_H
