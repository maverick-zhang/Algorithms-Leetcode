//
// Created by maverick on 2020/1/1.
//

#ifndef ALGORITHMS_Q102_LEVEL_ORDER_H
#define ALGORITHMS_Q102_LEVEL_ORDER_H

//给定一个二叉树，返回其按层次遍历的节点值。 （即逐层地，从左到右访问所有节点）。

#include <vector>
#include <queue>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};


class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;

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
            if (res.size() == layer)
                res.emplace_back(vector<int>());
            res[layer].push_back(p->val);
            if (p->left)
                que.push(make_pair(p->left, layer+1));
            if (p->right)
                que.push((make_pair(p->right, layer + 1)));
            que.pop();
        }
        return res;

    }
};

#endif //ALGORITHMS_Q102_LEVEL_ORDER_H
