//
// Created by maverick on 2020/1/5.
//

#ifndef ALGORITHMS_Q113_FIND_PATH_H
#define ALGORITHMS_Q113_FIND_PATH_H

#include <vector>
#include <queue>
#include <stack>
using namespace std;


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

//给定一个二叉树和一个目标和，找到所有从根节点到叶子节点路径总和等于给定目标和的路径。
//
//说明: 叶子节点是指没有子节点的节点。
//
//示例:
//给定如下二叉树，以及目标和 sum = 22，
//
//              5
//             / \
//            4   8
//           /   / \
//          11  13  4
//         /  \    / \
//        7    2  5   1

class Solution {
    void find_path(TreeNode * root, int sum, stack<vector<int>> & st, vector<vector<int>> & res)
    {
        if (root == nullptr)
        {
            if (!st.empty())
                st.pop();
            return;

        }
        st.top().push_back(root->val);
        if (root->val == sum and !root->left and !root->right)
        {
            res.push_back(st.top());
            st.pop();
            return;
        }
        st.push(st.top());
        find_path(root->left, sum - root->val, st, res);
        find_path(root->right, sum - root->val, st, res);
    }
public:
    //使用一个栈记录递归过程中的路径节点上的值
    //构建一个递归函数
    //递归的终止条件为为叶节点，若此叶节点刚好符合sum=val,即找到了一条路径
    //若为非叶节点则继续递归
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>> res;

        if (root == nullptr)
            return res;

        stack<vector<int>> st;
        vector<int> vt;
        st.push(vt);

        find_path(root, sum, st, res);

        return res;

    }
};


//非递归
vector<vector<int>> pathSum(TreeNode* root, int sum) {
    vector<vector<int>> ans; vector<int> curr; //分别记录所有满足条件的路径、一条满足条件的路径
    if (!root) return ans;
    stack<TreeNode*> stk; TreeNode *prev = nullptr;
    while (root || !stk.empty()) { //模拟系统递归栈
        while (root) {
            stk.push(root); sum -= root->val; curr.push_back(root->val); //入栈、更新剩余和、路径
            root = root->left;
        }//递归访问左结点

        root = stk.top(); //不能再左了，取得右拐点（根结点）
        if (!root->left && !root->right && (sum == 0)) { //条件：是叶子结点且剩余和为0
            ans.push_back(curr); //满足条件，保存路径
        }

        if (!root->right || root->right == prev) { //右结点不存在或已经访问 回溯
            stk.pop(); sum += root->val; curr.pop_back(); //出栈、更新剩余和、路径
            prev = root; //标记已访问
            root = nullptr; //用于回溯到上一级
        }
        else { //递归访问右结点
            root = root->right;
        }
    }
    return ans;
}




#endif //ALGORITHMS_Q113_FIND_PATH_H
