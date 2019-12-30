//
// Created by maverick on 2019/12/27.
//

#ifndef ALGORITHMS_Q445_ADD_TWO_NUMBER2_H
#define ALGORITHMS_Q445_ADD_TWO_NUMBER2_H

#include <stack>
using namespace std;

//给定两个非空链表来代表两个非负整数。数字最高位位于链表开始位置。它们的每个节点只存储单个数字。将这两数相加会返回一个新的链表。
//
// 
//
//你可以假设除了数字 0 之外，这两个数字都不会以零开头。
//
//进阶:
//
//如果输入链表不能修改该如何处理？换句话说，你不能对列表中的节点进行翻转。
//
//示例:
//
//输入: (7 -> 2 -> 4 -> 3) + (5 -> 6 -> 4)
//输出: 7 -> 8 -> 0 -> 7

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        stack<int> st1;
        stack<int> st2;

        ListNode * cur_l1 = l1;
        ListNode * cur_l2 = l2;

        while (cur_l1 != nullptr)
        {
            st1.push(cur_l1->val);
            cur_l1 = cur_l1->next;
        }

        while (cur_l2 != nullptr)
        {
            st2.push(cur_l2->val);
            cur_l2 = cur_l2->next;
        }

        ListNode * res = nullptr;
        ListNode * cur_res = nullptr;
        int carry = 0;
        int digit = 0;
        int val_1 = 0, val_2 = 0;

        while (!st1.empty() or !st2.empty() or carry)
        {
            if (!st1.empty())
            {
                val_1 = st1.top();
                st1.pop();
            }
            else
                val_1 = 0;
            if (!st2.empty())
            {
                val_2 = st2.top();
                st2.pop();
            }
            else
                val_2 = 0;
            digit = (carry + val_1 + val_2) % 10;
            carry = (carry + val_1 + val_2) / 10;
            cur_res = new ListNode(digit);
            cur_res->next = res;
            res = cur_res;
        }

        return res;
    }
};

#endif //ALGORITHMS_Q445_ADD_TWO_NUMBER2_H
