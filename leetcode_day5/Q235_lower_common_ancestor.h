//
// Created by maverick on 2020/1/6.
//

#ifndef ALGORITHMS_Q235_LOWER_COMMON_ANCESTOR_H
#define ALGORITHMS_Q235_LOWER_COMMON_ANCESTOR_H

//给定一个二叉搜索树, 找到该树中两个指定节点的最近公共祖先。

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {

        if (root == nullptr)
            return nullptr;

        if (p->val > root->val and q->val > root->val)
            return lowestCommonAncestor(root->right, p, q);
        if (p->val < root->val and q->val < root->val)
            return lowestCommonAncestor(root->left, p, q);

        return root;
    }
};
#endif //ALGORITHMS_Q235_LOWER_COMMON_ANCESTOR_H
