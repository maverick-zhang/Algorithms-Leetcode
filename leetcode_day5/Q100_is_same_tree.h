//
// Created by maverick on 2020/1/5.
//

#ifndef ALGORITHMS_Q100_IS_SAME_TREE_H
#define ALGORITHMS_Q100_IS_SAME_TREE_H

//给定两个二叉树，编写一个函数来检验它们是否相同。
//
//如果两个树在结构上相同，并且节点具有相同的值，则认为它们是相同的。
//
//示例 1:
//
//输入:       1         1
//          / \       / \
//         2   3     2   3
//
//[1,2,3],   [1,2,3]
//
//输出: true
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {

        if (p and q)
        {
            if (p->val != q->val)
                return false;
        }

        if ((p and !q) or (q and !p))
            return false;

        if (!p and !q)
            return true;

        return isSameTree(p->left, q->left) and isSameTree(p->right, q->right);


    }
};


#endif //ALGORITHMS_Q100_IS_SAME_TREE_H
