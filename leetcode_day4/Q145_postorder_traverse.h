//
// Created by maverick on 2019/12/31.
//

#ifndef ALGORITHMS_Q145_POSTORDER_TRAVERSE_H
#define ALGORITHMS_Q145_POSTORDER_TRAVERSE_H

#include <vector>
#include <stack>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

using namespace std;
//class Solution {
//private:
//    void traverse(TreeNode * node, vector<int> & vt)
//    {
//        if (node == nullptr)
//            return;
//        traverse(node->left, vt);
//        traverse(node->right, vt);
//        vt.push_back(node->val);
//    }
//public:
//    vector<int> postorderTraversal(TreeNode* root) {
//
//        vector<int> res;
//        traverse(root, res);
//        return res;
//    }
//};

class Solution
{
public:
    vector<int> postorderTraversal(TreeNode * root)
    {
        stack<TreeNode *> st;
        vector<int> res;
        TreeNode * p = root;

        while (!st.empty() or p)
        {
            while (p)
            {
                st.push(p);
                p = (p->left)?p->left:p->right;
            }

            p = st.top();
            st.pop();
            res.push_back(p->val);
            if (!st.empty() and p == st.top()->left)
                p = st.top()->right;
            else
                p = nullptr;
        }

        return res;
    }
};

#endif //ALGORITHMS_Q145_POSTORDER_TRAVERSE_H
