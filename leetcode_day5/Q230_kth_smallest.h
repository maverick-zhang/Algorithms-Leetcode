//
// Created by maverick on 2020/1/6.
//

#ifndef ALGORITHMS_Q230_KTH_SMALLEST_H
#define ALGORITHMS_Q230_KTH_SMALLEST_H

#include <stack>

//给定一个二叉搜索树，编写一个函数 kthSmallest 来查找其中第 k 个最小的元素。

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

//使用中序遍历，遍历到的第K个元素即为第K小
using namespace std;
class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {

        stack<TreeNode *> st;
        TreeNode * p = root;
        while (p or !st.empty())
        {
            if (!p)
            {
                p = st.top();
                if (k == 1)
                    return p->val;
                k -= 1;
                st.pop();
                p = p->right;
                continue;
            }
            while (p->left)
            {
                st.push(p);
                p = p->left;
            }
            if (k == 1)
                return p->val;
            else
                k -= 1;
            p = p->right;
        }
        return 0;

    }
};

#endif //ALGORITHMS_Q230_KTH_SMALLEST_H
