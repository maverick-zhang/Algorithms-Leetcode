//
// Created by maverick on 2020/1/5.
//

#ifndef ALGORITHMS_Q226_INVERT_TREE_H
#define ALGORITHMS_Q226_INVERT_TREE_H

#include <algorithm>

//翻转一棵二叉树。
//
//示例：
//
//输入：
//
//     4
//   /   \
//  2     7
// / \   / \
//1   3 6   9
//输出：
//
//     4
//   /   \
//  7     2
// / \   / \
//9   6 3   1


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};
using namespace std;

class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {

        if (root == nullptr)
            return root;

        invertTree(root->left);
        invertTree(root->right);
        swap(root->left, root->right);

        return root;

    }
};

#endif //ALGORITHMS_Q226_INVERT_TREE_H
