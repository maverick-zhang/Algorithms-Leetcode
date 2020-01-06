//
// Created by maverick on 2020/1/6.
//

#ifndef ALGORITHMS_Q450_DELETE_BST_NODE_H
#define ALGORITHMS_Q450_DELETE_BST_NODE_H

//给定一个二叉搜索树的根节点 root 和一个值 key，删除二叉搜索树中的 key 对应的节点，并保证二叉搜索树的性质不变。返回二叉搜索树（有可能被更新）的根节点的引用。
//
//一般来说，删除节点可分为两个步骤：
//
//首先找到需要删除的节点；
//如果找到了，删除它。

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) {


        TreeNode * father = nullptr;
        TreeNode * p;
        TreeNode * to_delete;

        if (root == nullptr)
            return nullptr;

        p = root;
        while (p and key != p->val)
        {
            father = p;
            if (p->val > key)
                p = p->left;
            else
                p = p->right;
        }

        //如果没有找到待删除的节点
        if (!p)
            return root;
        //寻找到待删除的节点
        to_delete = p;


        //如果是叶节点，直接删除
        if (to_delete->left == nullptr and to_delete->right == nullptr)
        {
            if (father == nullptr)
                return nullptr;
            if (father->left == to_delete)
                father->left = nullptr;
            else
                father->right = nullptr;
            return root;
        }

        //非叶子节点
        //找到该节点的右子树的最左叶节点
        TreeNode * to_connect = to_delete->right;
        TreeNode * pre_to_connect = to_delete->right;
        while (to_connect and to_connect->left)
        {
            pre_to_connect = to_connect;
            to_connect = to_connect->left;
        }
        //右子节点为空
        if (pre_to_connect == nullptr)
            to_connect = to_delete->left;
        else
        {
            pre_to_connect->left = to_connect->right;
            to_connect->left = to_delete->left;
            if (to_connect != to_delete->right)
                to_connect->right = to_delete->right;

        }

        if (father == nullptr)
            return to_connect;

        if (father->left == to_delete)
            father->left = to_connect;
        else
            father->right = to_connect;
        return root;
    }
};

#endif //ALGORITHMS_Q450_DELETE_BST_NODE_H
