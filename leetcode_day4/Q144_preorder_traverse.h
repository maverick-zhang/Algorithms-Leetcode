//
// Created by maverick on 2019/12/31.
//

#ifndef ALGORITHMS_Q144_PREORDER_TRAVERSE_H
#define ALGORITHMS_Q144_PREORDER_TRAVERSE_H

#include <vector>
#include <stack>

//给定一个二叉树，返回它的 前序 遍历。返回值的数组
//采用递归和非递归两种形式

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

//递归法
//class Solution {
//private:
//    void traverse(TreeNode * node, vector<int> & vt)
//    {
//        if (node == nullptr)
//            return;
//        vt.push_back(node->val);
//        traverse(node->left, vt);
//        traverse(node->right, vt);
//    }
//public:
//    vector<int> preorderTraversal(TreeNode* root) {
//
//        vector<int> res;
//        traverse(root, res);
//        return res;
//    }
//};


//非递归法
class Solution
{
public:
    vector<int> preorderTraversal(TreeNode * root)
    {
        stack<TreeNode *> st;
        vector<int> res;
        TreeNode * cur = nullptr;

        st.push(root);
        while (!st.empty())
        {
            cur = st.top();
            st.pop();
            if (cur == nullptr)
                continue;
            res.push_back(cur->val);
            st.push(cur->right);
            st.push(cur->left);
        }

        return res;
    }
};




#endif //ALGORITHMS_Q144_PREORDER_TRAVERSE_H
