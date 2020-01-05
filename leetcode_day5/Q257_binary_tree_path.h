//
// Created by maverick on 2020/1/5.
//

#ifndef ALGORITHMS_Q257_BINARY_TREE_PATH_H
#define ALGORITHMS_Q257_BINARY_TREE_PATH_H

#include <string>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

//给定一个二叉树，返回所有从根节点到叶子节点的路径。
//
//说明: 叶子节点是指没有子节点的节点。
//
//示例:
//
//输入:
//
//      1
//    /   \
//    2     3
//    \
//     5
//
//输出: ["1->2->5", "1->3"]

class Solution {
public:
    vector<string> binaryTreePaths(TreeNode* root) {

        vector<string> res;
        if (root == nullptr)
            return res;

        if (!root->left and !root->right)
            res.push_back(to_string(root->val));

        vector<string> left_res = binaryTreePaths(root->left);
        vector<string> right_res = binaryTreePaths(root->right);

        for (const string & str: left_res)
            res.push_back(to_string(root->val)+"->"+str);
        for (const string & str: right_res)
            res.push_back(to_string(root->val)+"->"+str);

        return res;
    }
};



#endif //ALGORITHMS_Q257_BINARY_TREE_PATH_H
