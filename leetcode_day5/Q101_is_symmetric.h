//
// Created by maverick on 2020/1/5.
//

#ifndef ALGORITHMS_Q101_IS_SYMMETRIC_H
#define ALGORITHMS_Q101_IS_SYMMETRIC_H

#include <queue>

//给定一个二叉树，检查它是否是镜像对称的。
//
//例如，二叉树 [1,2,2,3,4,4,3] 是对称的。
//
//    1
//   / \
//  2   2
// / \ / \
//3  4 4  3
//但是下面这个 [1,2,2,null,3,null,3] 则不是镜像对称的:
//
//    1
//   / \
//  2   2
//   \   \
//   3    3

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

using namespace std;

class Solution {

    bool is_symmetric(TreeNode *p1, TreeNode *p2)
    {
        if (p1 and p2 and p1->val == p2->val)
            return is_symmetric(p1->left, p2->right) and is_symmetric(p1->right, p2->left);
        else if (!p1 and !p2)
            return true;
        else
            return false;
    }

public:
    bool isSymmetric(TreeNode* root) {

        if (root == nullptr)
            return true;

        return is_symmetric(root->left, root->right);
    }
};




#endif //ALGORITHMS_Q101_IS_SYMMETRIC_H
