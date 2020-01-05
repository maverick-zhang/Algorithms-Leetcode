//
// Created by maverick on 2020/1/5.
//

#ifndef ALGORITHMS_Q222_COUNT_NODES_H
#define ALGORITHMS_Q222_COUNT_NODES_H

#include <queue>
#include <cmath>

//给出一个完全二叉树，求出该树的节点个数。
//
//说明：
//
//完全二叉树的定义如下：在完全二叉树中，除了最底层节点可能没填满外，其余每层节点数都达到最大值，并且最下面一层的节点都集中在该层最左边的若干位置。若最底层为第 h 层，则该层包含 1~ 2h 个节点。
//
//示例:
//
//输入:
//    1
//   / \
//  2   3
// / \  /
//4  5 6
//
//输出: 6

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};
using namespace std;
class Solution {
public:
    int countNodes(TreeNode* root) {
        if (root == nullptr)
            return 0;
        queue<TreeNode *> que;
        int res = 1;
        que.push(root);
        TreeNode *p;
        while (!que.empty())
        {
            p = que.front();
            que.pop();
            if (p->left)
            {
                que.push(p->left);
                res ++;
            }
            if (p->right)
            {
                que.push(p->right);
                res ++;
            }
        }

        return res;


    }
};

//递归方法：利用满二叉树的性质

class Solution2
{
public:
    int countNodes(TreeNode * root)
    {
        if (root == nullptr)
            return 0;

        int l_height = 0, r_height = 0, l_sum = 0, r_sum = 0;

        TreeNode *p = root->left;
        while (p)
        {
            l_height ++;
            p = p->left;
        }
        p = root->right;
        while (p)
        {
            r_height ++;
            p = p->left;       //注意是left
        }
        if (l_height == r_height)    //左子树的高度和右子树的高度相等，则左子树为满二叉树
        {
            l_sum = pow(2, l_height) - 1;
            r_sum = countNodes(root->right);
        }
        else
        {
            r_sum = pow(2, r_height);
            l_sum = countNodes(root->left);
        }

        return l_sum + r_sum + 1;

    }
};

#endif //ALGORITHMS_Q222_COUNT_NODES_H
