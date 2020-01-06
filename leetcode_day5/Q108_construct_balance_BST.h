//
// Created by maverick on 2020/1/6.
//

#ifndef ALGORITHMS_Q108_CONSTRUCT_BALANCE_BST_H
#define ALGORITHMS_Q108_CONSTRUCT_BALANCE_BST_H

#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

//将一个按照升序排列的有序数组，转换为一棵高度平衡二叉搜索树。
class Solution {
private:
    TreeNode * construct(int left, int right, vector<int> & nums)
    {
        if (right < left)
            return nullptr;
        int mid = (left + right)/2;
        TreeNode * root = new TreeNode(nums[mid]);
        if (left == right)
            return root;
        else
        {
            root->left = construct(left, mid - 1, nums);
            root->right = construct(mid + 1, right, nums);
            return root;
        }
    }
public:

    //对数组去中间的值作为根节点，然后用左侧数组构造左平衡二叉搜索子树，右侧数组构建右二叉搜索平衡子树
    //递归停止的条件为数组只有一个值
    TreeNode* sortedArrayToBST(vector<int>& nums) {

        return construct(0, nums.size()-1, nums);

    }
};
#endif //ALGORITHMS_Q108_CONSTRUCT_BALANCE_BST_H
