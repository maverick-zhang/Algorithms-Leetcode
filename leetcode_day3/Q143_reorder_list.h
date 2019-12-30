//
// Created by maverick on 2019/12/30.
//

#ifndef ALGORITHMS_Q143_REORDER_LIST_H
#define ALGORITHMS_Q143_REORDER_LIST_H

#include <stack>

//给定一个单链表 L：L0→L1→…→Ln-1→Ln ，
//将其重新排列后变为： L0→Ln→L1→Ln-1→L2→Ln-2→…
//
//你不能只是单纯的改变节点内部的值，而是需要实际的进行节点交换。
//
//示例 1:
//
//给定链表 1->2->3->4, 重新排列为 1->4->2->3.

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

//class Solution {
//public:
//    void reorderList(ListNode* head) {
//
//        if (head == nullptr or head->next == nullptr)
//            return;
//        ListNode * tail = head;
//        while (tail->next)
//            tail = tail->next;
//        ListNode * p;
//        ListNode * cur = head;
//
//        while (cur->next->next != nullptr)
//        {
//            p = cur;
//            while (p->next != tail)
//                p = p->next;
//            tail->next = cur->next;
//            cur->next = tail;
//            tail = p;
//            tail->next = nullptr;
//            cur = cur->next->next;
//        }
//    }
//};


//使用一个栈，把链表全部入栈
//从头遍历链表，遍历一个弹出一个，直到遍历一半的链表
using namespace std;
class Solution {
public:
    void reorderList(ListNode *head) {
        stack<ListNode *> st;
        ListNode *p = head;
        int n = 0;
        while (p)
        {
            n ++;
            st.push(p);
            p = p->next;
        }

        p = head;
        for (int i = 0; i < n/2; ++i) {
            st.top()->next = p->next;
            p->next = st.top();
            st.pop();
            p = p->next->next;
        }

        if (p)
            p->next = nullptr;

    }
};

#endif //ALGORITHMS_Q143_REORDER_LIST_H
