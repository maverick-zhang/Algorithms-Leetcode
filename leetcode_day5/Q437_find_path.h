//
// Created by maverick on 2020/1/5.
//

#ifndef ALGORITHMS_Q437_FIND_PATH_H
#define ALGORITHMS_Q437_FIND_PATH_H

//给定一个二叉树，它的每个结点都存放着一个整数值。
//
//找出路径和等于给定数值的路径总数。
//
//路径不需要从根节点开始，也不需要在叶子节点结束，但是路径方向必须是向下的（只能从父节点到子节点）。
//
//二叉树不超过1000个节点，且节点数值范围是 [-1000000,1000000] 的整数。
//
//示例：
//
//root = [10,5,-3,3,2,null,11,3,-2,null,1], sum = 8
//
//      10
//     /  \
//    5   -3
//   / \    \
//  3   2   11
// / \   \
//3  -2   1
//
//返回 3。和等于 8 的路径有:
//
//1.  5 -> 3
//2.  5 -> 2 -> 1
//3.  -3 -> 11

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
private:
    //寻找包含该节点的路径
    int find_path(TreeNode *root, int sum)
    {
        int res = 0;
        if (root == nullptr)
            return 0;
        if (root->val == sum)
            res ++;
        res += find_path(root->left, sum - root->val);
        res += find_path(root->right, sum - root->val);
        return res;
    }
public:

    //使用两层递归
    //第一层
    //对于每一个节点如果包含当前节点的，寻找路径，不包含当前节点，则递归其子节点
    //第二层即为包含当前节点的路径
    int pathSum(TreeNode* root, int sum) {

        if (root == nullptr)
            return 0;
        int res = 0;
        res += find_path(root, sum);
        res += pathSum(root->left, sum);
        res += pathSum(root->right, sum);
        return res;
    }
};

#endif //ALGORITHMS_Q437_FIND_PATH_H
