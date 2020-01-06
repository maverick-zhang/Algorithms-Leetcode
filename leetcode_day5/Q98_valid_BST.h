//
// Created by maverick on 2020/1/6.
//

#ifndef ALGORITHMS_Q98_VALID_BST_H
#define ALGORITHMS_Q98_VALID_BST_H

//给定一个二叉树，判断其是否是一个有效的二叉搜索树。
//
//假设一个二叉搜索树具有如下特征：
//
//节点的左子树只包含小于当前节点的数。
//节点的右子树只包含大于当前节点的数。
//所有左子树和右子树自身必须也是二叉搜索树

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {

    bool is_valid(TreeNode * root)
    {
        if (root == nullptr)
            return true;

        if ((root->left and root->left->val >= root->val) or(root->right and root->right->val <= root->val))
            return false;

        return isValidBST(root->left) and isValidBST(root->right);
    }

public:
    bool isValidBST(TreeNode* root) {

        if (root == nullptr)
            return true;

        TreeNode *p = root->left;
        while (p)
        {
            if (p->val >= root->val)
                return false;
            p = p->right;
        }

        p = root->right;
        while (p)
        {
            if (p->val <= root->val)
                return false;
            p = p->left;
        }

        return is_valid(root);
    }
};


//优化
class Solution2
{
private:
    TreeNode *pre;
public:
    //中序遍历 左->根->右 刚好满足二叉搜索树的定义
    bool isValidBST(TreeNode * root)
    {
        if(root == nullptr)
            return true;
        if(!isValidBST(root->left)){
            return false;
        }
        if(pre && pre->val >= root->val)
            return false;
        pre = root;
        if(!isValidBST(root->right))
            return false;
        return true;
    }
};




#endif //ALGORITHMS_Q98_VALID_BST_H
