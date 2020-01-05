//
// Created by maverick on 2020/1/5.
//

#ifndef ALGORITHMS_Q129_SUM_NUMBERS_H
#define ALGORITHMS_Q129_SUM_NUMBERS_H

#include <stack>
#include <vector>

//给定一个二叉树，它的每个结点都存放一个 0-9 的数字，每条从根到叶子节点的路径都代表一个数字。
//
//例如，从根到叶子节点路径 1->2->3 代表数字 123。
//
//计算从根到叶子节点生成的所有数字之和。
//
//说明: 叶子节点是指没有子节点的节点。
//
//示例 1:
//
//输入: [1,2,3]
//    1
//   / \
//  2   3
//输出: 25
//解释:
//从根到叶子节点路径 1->2 代表数字 12.
//从根到叶子节点路径 1->3 代表数字 13.
//因此，数字总和 = 12 + 13 = 25.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};
using namespace std;
class Solution {
public:
    int sumNumbers(TreeNode* root) {

        if (root == nullptr)
            return 0;
        int res = 0;
        //使用深度优先遍历
        stack<pair<TreeNode*, bool>> st;
        vector<int> path;
        TreeNode *p = root;

        while (p or !st.empty())
        {
            while (p)
            {
                st.push(make_pair(p, false));
                path.push_back(p->val);
                p = p->left;
            }
            //到达最左端
            //如果最后一个节点为叶节点，则找到了一条路径，对路径进行求和，并弹出最后一个节点
            p = st.top().first;
            if (!p->right)
            {
                int path_sum = 0;
                for (int i = 0; i < path.size(); ++i)
                    path_sum = 10 * path_sum + path[i];
                res += path_sum;
                path.pop_back();
                st.pop();
                //对于栈顶的节点，如果其标记为已经访问过，或者其没有右子树，则弹出
                while (!st.empty() and (st.top().second or !st.top().first->right))
                {
                    st.pop();
                    path.pop_back();
                }
            }

            //拐到右子树
            if (!st.empty())
            {
                p = st.top().first->right;
                st.top().second = true;
            } else
                break;
        }
        return res;
    }
};





#endif //ALGORITHMS_Q129_SUM_NUMBERS_H
