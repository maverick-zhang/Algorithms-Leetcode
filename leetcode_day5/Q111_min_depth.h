//
// Created by maverick on 2020/1/5.
//

#ifndef ALGORITHMS_Q111_MIN_DEPTH_H
#define ALGORITHMS_Q111_MIN_DEPTH_H

#include <algorithm>

//给定一个二叉树，找出其最小深度。
//
//最小深度是从根节点到最近叶子节点的最短路径上的节点数量。
//
//说明: 叶子节点是指没有子节点的节点。
//
//示例:
//
//给定二叉树 [3,9,20,null,null,15,7],
//
//    3
//   / \
//  9  20
//    /  \
//   15   7
//返回它的最小深度  2.

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

using namespace std;

class Solution {
public:
    int minDepth(TreeNode* root) {

        if (root == nullptr)
            return 0;

        if (root->left == nullptr and root->right == nullptr)
            return 1;

        if (root->left == nullptr)
            return minDepth(root->right) + 1;

        if (root->right == nullptr)
            return minDepth(root->left) + 1;

        return min(minDepth(root->left), minDepth(root->right)) + 1;

    }
};



#endif //ALGORITHMS_Q111_MIN_DEPTH_H
