//
// Created by maverick on 2020/1/5.
//

#ifndef ALGORITHMS_Q110_IS_BALANCED_H
#define ALGORITHMS_Q110_IS_BALANCED_H

#include <queue>
#include <algorithm>
#include <cmath>

//给定一个二叉树，判断它是否是高度平衡的二叉树
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

using namespace std;

class Solution {
public:
    bool isBalanced(TreeNode* root) {

        if (root == nullptr)
            return true;
        //<节点，节点的所在层>
        queue<pair<TreeNode *, int>> que;
        que.push(make_pair(root, 1));
        TreeNode *p;
        int layer;
        bool found = false;
        int min = 1;
        int max = 1;
        while (!que.empty())
        {
            p = que.front().first;
            layer = que.front().second;
            que.pop();
            if (p->left)
            {
                que.push(make_pair(p->left, layer+1));
            }
            if (p->right)
                que.push(make_pair(p->right, layer+1));

            if (!p->left and !p->right)
            {
                if (que.empty())
                    max = layer;
                if (!found)
                {
                    min = layer;
                    found = true;
                }
            }
            if ((!p->left and p->right) or (p->left and !p->right))
            {
                if (!found)
                {
                    min = layer;
                    found = true;
                }
            }

        }
        return (max - min <= 1);
    }
};

class Solution2
{
    int height(TreeNode * root)
    {
        if (root == nullptr)
            return 0;
        queue<pair<TreeNode *, int>> que;
        que.push(make_pair(root, 1));
        TreeNode *p;
        int layer = 1;
        while (!que.empty())
        {
            p = que.front().first;
            layer = que.front().second;
            que.pop();
            if (p->left)
                que.push(make_pair(p->left, layer+1));
            if (p->right)
                que.push(make_pair(p->right, layer+1));
            if (!p->left and !p->right)
            {
                if (que.empty())
                    return layer;
            }
        }

        return layer;
    }
public:
    bool isBalanced(TreeNode * root)
    {
        if (root == nullptr)
            return true;
        if (abs(height(root->left) - height(root->right)) > 1)
            return false;
        return isBalanced(root->left) and isBalanced(root->right);
    }
};

//优化递归
class Solution3
{
private:
    //返回该树的深度，如果深度为-1则表示左右两颗子树高度不相等
    int depth(TreeNode * root)
    {
        if (root == nullptr)
            return 0;
        int l_height = depth(root->left);
        if (l_height == -1)
            return -1;
        int r_height = depth(root->right);
        if (r_height == -1)
            return -1;
        return (abs(l_height - r_height) > 1)?-1:max(l_height, r_height) + 1;

    }

public:
    bool isBalanced(TreeNode *root)
    {
        return depth(root) != -1;
    }
};


#endif //ALGORITHMS_Q110_IS_BALANCED_H
