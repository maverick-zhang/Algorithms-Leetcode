//
// Created by maverick on 2019/12/30.
//

#ifndef ALGORITHMS_Q25_REVERSE_K_GROUP_H
#define ALGORITHMS_Q25_REVERSE_K_GROUP_H

#include <stack>
using namespace std;
//给你一个链表，每 k 个节点一组进行翻转，请你返回翻转后的链表。
//
//k 是一个正整数，它的值小于或等于链表的长度。
//
//如果节点总数不是 k 的整数倍，那么请将最后剩余的节点保持原有顺序。
//
//示例 :
//
//给定这个链表：1->2->3->4->5
//
//当 k = 2 时，应当返回: 2->1->4->3->5
//
//当 k = 3 时，应当返回: 3->2->1->4->5

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};


class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {

        if (k <= 1)
            return head;

        auto * dummy = new ListNode(0);
        dummy->next = head;

        //区间pre->left->..->right->next
        //翻转[left, right]内的所有节点,其中right - left = k - 1;
        ListNode * left = head;
        ListNode * pre = dummy;
        stack<ListNode *> st;

        while (left)
        {
            //通过遍历找到right节点
            ListNode * cur = left;
            int i = 1;
            while (i <= k)
            {
                if (cur == nullptr)
                {
                    pre->next = left;
                    head = dummy->next;
                    delete dummy;
                    return head;
                }
                i ++;
                st.push(cur);
                cur = cur->next;
            }
            left = cur;

            while (!st.empty())
            {
                if (st.size() == 1)
                    st.top()->next = nullptr;
                pre->next = st.top();
                pre = pre->next;
                st.pop();
            }

        }
        head = dummy->next;
        delete dummy;
        return head;
    }
};


#endif //ALGORITHMS_Q25_REVERSE_K_GROUP_H
