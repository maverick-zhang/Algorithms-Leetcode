//
// Created by maverick on 2020/1/5.
//

#ifndef ALGORITHMS_Q404_SUM_OF_LEFT_LEAVES_H
#define ALGORITHMS_Q404_SUM_OF_LEFT_LEAVES_H

//计算给定二叉树的所有左叶子之和。
//
//示例：
//
//    3
//   / \
//  9  20
//    /  \
//   15   7
//
//在这个二叉树中，有两个左叶子，分别是 9 和 15，所以返回 24
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    int sumOfLeftLeaves(TreeNode* root) {
        if (root == nullptr)
            return 0;
        int left_sum = 0, right_sum = 0;
        if ( root->left)
        {
            if (!root->left->left and !root->left->right)
                left_sum = root->left->val;
            else
                left_sum = sumOfLeftLeaves(root->left);
        }
        right_sum = sumOfLeftLeaves(root->right);
        return left_sum + right_sum;

    }
};


#endif //ALGORITHMS_Q404_SUM_OF_LEFT_LEAVES_H
