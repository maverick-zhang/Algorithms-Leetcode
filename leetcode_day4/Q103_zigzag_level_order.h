//
// Created by maverick on 2020/1/1.
//

#ifndef ALGORITHMS_Q103_ZIGZAG_LEVEL_ORDER_H
#define ALGORITHMS_Q103_ZIGZAG_LEVEL_ORDER_H

//给定一个二叉树，返回其节点值的锯齿形层次遍历。（即先从左往右，再从右往左进行下一层遍历，以此类推，层与层之间交替进行）。
//
//例如：
//给定二叉树 [3,9,20,null,null,15,7],
//
//   3
//  / \
//  9  20
//    /  \
//    15  7
//返回锯齿形层次遍历如下：
//
//[
//[3],
//[20,9],
//[15,7]
//]

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


class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> res;
        stack<TreeNode *> st;

        queue<pair<TreeNode *, int>> que;
        if (root == nullptr)
            return res;
        int layer = 0;
        int next_layer = 1;
        que.push(make_pair(root, 0));

        TreeNode * p;
        while (!que.empty())
        {
            layer = que.front().second;
            while (!que.empty() and que.front().second != next_layer)
            {
                p = que.front().first;

                if (res.size() == layer)
                    res.emplace_back(vector<int>());
                res[layer].push_back(p->val);

                if (layer % 2 == 0)
                {
                    if (p->left)
                        st.push(p->left);
                    if (p->right)
                        st.push(p->right);
                }
                else
                {
                    if (p->right)
                        st.push(p->right);
                    if (p->left)
                        st.push(p->left);
                }

                que.pop();

            }

            while (!st.empty())
            {
                que.push(make_pair(st.top(), layer + 1));
                st.pop();
            }

            next_layer ++;


        }
        return res;
    }
};



#endif //ALGORITHMS_Q103_ZIGZAG_LEVEL_ORDER_H
