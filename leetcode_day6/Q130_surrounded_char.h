//
// Created by maverick on 2020/1/7.
//

#ifndef ALGORITHMS_Q130_SURROUNDED_CHAR_H
#define ALGORITHMS_Q130_SURROUNDED_CHAR_H

//给定一个二维的矩阵，包含 'X' 和 'O'（字母 O）。
//
//找到所有被 'X' 围绕的区域，并将这些区域里所有的 'O' 用 'X' 填充。
//
//示例:
//
//X X X X
//X O O X
//X X O X
//X O X X

//[["O","X","X","O","X"],
// ["X","O","O","X","O"],
// ["X","O","X","O","X"],
// ["O","X","O","O","O"],
// ["X","X","O","X","O"]]

//[["O","X","X","O","X"],
// ["X","X","X","X","O"],
// ["X","X","X","O","X"],
// ["O","X","X","O","O"],
// ["X","X","O","X","O"]]

//[["O","X","X","O","X"],
// ["X","X","X","X","O"],
// ["X","X","X","O","X"],
// ["O","X","O","O","O"],
// ["X","X","O","X","O"]]

#include <vector>
using namespace std;
//
//class Solution {
//private:
//    vector<vector<bool>> surrounded;
//    bool in_area(int x, int y)
//    {
//        return x >= 0 and x < x_max and y >= 0 and y < y_max;
//    }
//
//    int x_max, y_max;
//
//    int direction[4][2] {{0, -1}, {-1, 0},{1, 0},{0, 1}};
//
//    bool is_surrounded (vector<vector<char>> & board, int x, int y, vector<vector<bool>> & visited)
//    {
//        visited[x][y] = true;
//        for (int i = 0; i < 4; ++i) {
//            int new_x = x + direction[i][0];
//            int new_y = y + direction[i][1];
//
//            if (!in_area(new_x, new_y))
//                return false;
//
//            if (!surrounded[new_x][new_y])
//                return false;
//
//            if (!visited[new_x][new_y] and board[new_x][new_y] == 'O')
//            {
//                if(!is_surrounded(board, new_x, new_y, visited))
//                    return false;
//            }
//
//        }
//        return true;
//    }
//
//    void dfs(vector<vector<char>> & board, int x, int y)
//    {
//        board[x][y] = 'X';
//        for (int i = 0; i < 4; ++i) {
//            int new_x = x + direction[i][0];
//            int new_y = y + direction[i][1];
//            if (in_area(new_x, new_y) and board[new_x][new_y] == 'O')
//                dfs(board, new_x, new_y);
//        }
//
//    }
//
//public:
//    void solve(vector<vector<char>>& board) {
//
//        x_max = board.size();
//        if(x_max < 3)
//            return;
//        y_max = board[0].size();
//        surrounded = vector<vector<bool>> (x_max, vector<bool>(y_max, true));
//        for (int i = 1; i < x_max - 1; ++i) {
//            for (int j = 1; j < y_max - 1; ++j) {
//                auto visited = vector<vector<bool>>(x_max, vector<bool>(y_max, false));
//                if (board[i][j] == 'O' )
//                {
//                    if (is_surrounded(board, i, j, visited))
//                        dfs(board, i, j);
//                    else
//                        surrounded[i][j] = false;
//                }
//            }
//        }
//    }
//};

//改变思路,从边界开始用dfs找到所有和边界相连的O，把其改变为’#‘,这一步做完后，剩下的O即为不联通的，将其改为X
//最后再把#改为O

class Solution
{
    bool in_area(int x, int y)
    {
        return x >= 0 and x < x_max and y >= 0 and y < y_max;
    }
    int x_max, y_max;

    int direction[4][2] {{0, -1}, {-1, 0},{1, 0},{0, 1}};

    void dfs(vector<vector<char>> & board, int x, int y)
    {
        board[x][y] = '#';
        for (int i = 0; i < 4; ++i) {
            int new_x = x + direction[i][0];
            int new_y = y + direction[i][1];
            if (in_area(new_x, new_y) and board[new_x][new_y] == 'O')
                dfs(board, new_x, new_y);
        }
    }

public:
    void solve(vector<vector<char>>& board)
    {

        x_max = board.size();
        if (x_max < 3)
            return;
        y_max = board[0].size();

        for (int i = 0; i < x_max; ++i) {
            for (int j = 0; j < y_max; ++j) {
                if ((i == x_max - 1 or j == y_max - 1 or i == 0 or j == 0) and board[i][j] == 'O' )
                    dfs(board, i, j);
            }
        }

        for (int k = 0; k < x_max; ++k) {
            for (int i = 0; i < y_max; ++i) {
                if (board[k][i] == 'O')
                    board[k][i] = 'X';
                if (board[k][i] == '#')
                    board[k][i] = 'O';
            }
        }


    }
};

#endif //ALGORITHMS_Q130_SURROUNDED_CHAR_H
