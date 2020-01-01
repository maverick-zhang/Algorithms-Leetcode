//
// Created by maverick on 2020/1/1.
//

#ifndef ALGORITHMS_Q199_RIGHT_SIDE_VIEW_H
#define ALGORITHMS_Q199_RIGHT_SIDE_VIEW_H

#include <vector>
#include <queue>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

//给定一棵二叉树，想象自己站在它的右侧，按照从顶部到底部的顺序，返回从右侧所能看到的节点值。
//
//示例:
//
//输入: [1,2,3,null,5,null,4]
//输出: [1, 3, 4]
//解释:
//
//   1            <---
// /   \
//2     3         <---
// \     \
//  5     4       <---

class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {

        vector<int> res;
        if (!root)
            return res;

        queue<pair<TreeNode *, int>> que;
        que.push(make_pair(root, 0));
        TreeNode *p;
        int layer;
        while (!que.empty())
        {
            layer = que.front().second;
            p = que.front().first;
            if (p->right)
                que.push(make_pair(p->right, layer+1));
            if (p->left)
                que.push(make_pair(p->left, layer + 1));
            if (layer == res.size())
                res.push_back(p->val);
            que.pop();
        }

        return res;
    }
};



#endif //ALGORITHMS_Q199_RIGHT_SIDE_VIEW_H
