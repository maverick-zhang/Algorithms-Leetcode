//
// Created by maverick on 2020/1/7.
//

#ifndef ALGORITHMS_Q79_SEARCH_WORD_H
#define ALGORITHMS_Q79_SEARCH_WORD_H

//给定一个二维网格和一个单词，找出该单词是否存在于网格中。
//
//单词必须按照字母顺序，通过相邻的单元格内的字母构成，其中“相邻”单元格是那些水平相邻或垂直相邻的单元格。同一个单元格内的字母不允许被重复使用。
//
//示例:
//
//board =
//[
//['A','B','C','E'],
//['S','F','C','S'],
//['A','D','E','E']
//]
//
//给定 word = "ABCCED", 返回 true.
//给定 word = "SEE", 返回 true.
//给定 word = "ABCB", 返回 false.

#include <vector>
#include <string>
using namespace std;

class Solution {
private:

    bool in_area(int x, int y)
    {
        return x >= 0 and x < x_max and y >= 0 and y < y_max;
    }

    int x_max, y_max;

    int direction[4][2] {{0, -1}, {0, 1},{1, 0},{-1, 0}};

    vector<vector<bool>> visited;

    //对于二维数组中的board[x][y]是否为word[index]
    bool find_char(vector<vector<char>> & board, string & word, int index, int x, int y)
    {
        if (index == word.size() - 1)
            return word[index] == board[x][y];

        if (word[index] == board[x][y])
        {
            visited[x][y] = true;
            for (int i = 0; i < 4; ++i) {
                int new_x = x + direction[i][0];
                int new_y = y +direction[i][1];
                if (in_area(new_x, new_y) and !visited[new_x][new_y])
                {
                    if (find_char(board, word, index + 1, new_x, new_y))
                        return true;
                }
            }
            visited[x][y] = false;
        }
        return false;
    }
public:
    bool exist(vector<vector<char>>& board, string word) {
        x_max = board.size();
        y_max = board[0].size();
        visited = vector<vector<bool>> (x_max, vector<bool>(y_max, false));

        for (int i = 0; i < x_max; ++i) {
            for (int j = 0; j < y_max; ++j) {
                if (find_char(board, word, 0, i, j))
                    return true;
            }
        }
        return false;
    }
};



#endif //ALGORITHMS_Q79_SEARCH_WORD_H
