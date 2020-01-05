//
// Created by maverick on 2020/1/5.
//

#ifndef ALGORITHMS_Q112_HAS_PATH_H
#define ALGORITHMS_Q112_HAS_PATH_H

//给定一个二叉树和一个目标和，判断该树中是否存在根节点到叶子节点的路径，这条路径上所有节点值相加等于目标和。
//
//说明: 叶子节点是指没有子节点的节点。
//
//示例: 
//给定如下二叉树，以及目标和 sum = 22，
//
//              5
//             / \
//            4   8
//           /   / \
//          11  13  4
//         /  \      \
//        7    2      1

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    bool hasPathSum(TreeNode* root, int sum) {

        if (root == nullptr)
            return false;
        if (root->val == sum and !root->left and !root->right)
            return true;
        return hasPathSum(root->left, sum - root->val) or hasPathSum(root->right, sum-root->val);
    }
};

#endif //ALGORITHMS_Q112_HAS_PATH_H
