//
// Created by maverick on 2020/1/6.
//

#ifndef ALGORITHMS_Q236_LOWEST_COMMON_ANCESTOR_H
#define ALGORITHMS_Q236_LOWEST_COMMON_ANCESTOR_H

//给定一个二叉树, 找到该树中两个指定节点的最近公共祖先。
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:

    //使用递归的思路
    //如果当前节点即为所求，那么有三种情况：1当前节点为p.2当前节点为q.3 p和q分别在当前节点的两个子树中
    //
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == nullptr or root == p or root == q)
            return root;

        TreeNode * left = lowestCommonAncestor(root->left, p, q);
        TreeNode * right = lowestCommonAncestor(root->right, p, q);

        //如果left和right都为非空，则root即为所求，直接返回，这属于第三种情况
        if (left and right)
            return root;

        //如果一个为空一个不为空，代表当前节点的一个子树中没有p和q，那么结果只能在另一个子树中
        //如果两个都是空，呢么返回也是空，代表答案不在该该节点以及子节点中，需要回溯到父节点
        return left?left:right;

    }
};
#endif //ALGORITHMS_Q236_LOWEST_COMMON_ANCESTOR_H
