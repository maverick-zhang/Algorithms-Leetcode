//
// Created by maverick on 2020/1/9.
//

#ifndef ALGORITHMS_Q337_ROB3_H
#define ALGORITHMS_Q337_ROB3_H

//在上次打劫完一条街道之后和一圈房屋后，小偷又发现了一个新的可行窃的地区。这个地区只有一个入口，我们称之为“根”。
//除了“根”之外，每栋房子有且只有一个“父“房子与之相连。一番侦察之后，聪明的小偷意识到“这个地方的所有房屋的排列类似于一棵二叉树”。
//如果两个直接相连的房子在同一天晚上被打劫，房屋将自动报警。
//
//计算在不触动警报的情况下，小偷一晚能够盗取的最高金额。

#include <unordered_map>
using namespace std;


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};



//递归求解

class Solution {

    unordered_map<TreeNode*, int> memo;

public:
    int rob(TreeNode* root) {

        if (root == nullptr)
            return 0;
        if (memo.find(root) != memo.end())
            return memo[root];

        int steal_this_node = root->val;
        int not_steal = 0;
        if (root->left)
        {
            steal_this_node += rob(root->left->left) + rob(root->left->right);
            not_steal += rob(root->left);
        }
        if (root->right)
        {
            steal_this_node += rob(root->right->left) + rob(root->right->right);
            not_steal += rob(root->right);
        }
        memo[root] = max(steal_this_node, not_steal);
        return memo[root];
    }
};

//动态规划:首先要获得所有叶节点



#endif //ALGORITHMS_Q337_ROB3_H
