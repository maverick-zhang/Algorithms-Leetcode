//
// Created by maverick on 2020/1/1.
//

#ifndef ALGORITHMS_Q107_LEVEL_ORDER2_H
#define ALGORITHMS_Q107_LEVEL_ORDER2_H

#include <vector>
#include <queue>
#include <stack>
using namespace std;


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};
//给定一个二叉树，返回其节点值自底向上的层次遍历。 （即按从叶子节点所在层到根节点所在的层，逐层从左向右遍历）
//
//例如：
//给定二叉树 [3,9,20,null,null,15,7],
//
//   3
//  / \
//  9  20
//    /  \
//   15   7
class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> res;
        stack<vector<int>> st;
        queue<pair<TreeNode *, int>> que;
        if (root == nullptr)
            return res;
        int layer = 0;
        que.push(make_pair(root, 0));

        TreeNode * p;
        while (!que.empty())
        {
            p = que.front().first;
            layer = que.front().second;
            if (st.size() == layer)
                st.push(vector<int >());
            st.top().push_back(p->val);
            if (p->left)
                que.push(make_pair(p->left, layer+1));
            if (p->right)
                que.push((make_pair(p->right, layer + 1)));
            que.pop();
        }

        while (!st.empty())
        {
            res.push_back(st.top());
            st.pop();
        }
        return res;
    }
};


#endif //ALGORITHMS_Q107_LEVEL_ORDER2_H
