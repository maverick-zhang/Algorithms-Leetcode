//
// Created by maverick on 2019/12/31.
//

#ifndef ALGORITHMS_Q94_INORDER_TRAVERSE_H
#define ALGORITHMS_Q94_INORDER_TRAVERSE_H

#include <vector>
#include <stack>

//给定一个二叉树，返回它的 中序 遍历。返回值的数组
//采用递归和非递归两种形式

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};


//递归算法
//class Solution {
//private:
//    void traverse(TreeNode * node, vector<int> & vt)
//    {
//        if (node == nullptr)
//            return;
//        traverse(node->left, vt);
//        vt.push_back(node->val);
//        traverse(node->right, vt);
//    }
//public:
//    vector<int> inorderTraversal(TreeNode* root) {
//
//        vector<int> res;
//        traverse(root, res);
//        return res;
//    }
//};


//非递归算法
class Solution
{
public:
    vector<int> inorderTraversal(TreeNode * root)
    {
        vector<int> res;
        if (root == nullptr)
            return res;

        TreeNode *p = root;
        stack<pair<TreeNode *, bool>> st;

        while (!st.empty() or p)
        {
            if (p)
            {
                if (p->right)
                    st.push(make_pair(p->right, false));
                st.push(make_pair(p, true));
                p = p->left;
                continue;
            }

            p = st.top().first;
            while (st.top().second)
            {
                res.push_back(p->val);
                st.pop();
                if (st.empty())
                    break;
                else
                    p = st.top().first;
            }
            if (!st.empty())
                st.pop();
            else
                break;
        }
        return res;
    }
};

#endif //ALGORITHMS_Q94_INORDER_TRAVERSE_H
