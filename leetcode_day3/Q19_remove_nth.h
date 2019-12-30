//
// Created by maverick on 2019/12/30.
//

#ifndef ALGORITHMS_Q19_REMOVE_NTH_H
#define ALGORITHMS_Q19_REMOVE_NTH_H

//给定一个链表，删除链表的倒数第 n 个节点，并且返回链表的头结点。
//
//示例：
//
//给定一个链表: 1->2->3->4->5, 和 n = 2.
//
//当删除了倒数第二个节点后，链表变为 1->2->3->5.

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:

    //使用一个双指针窗口[p, q], p - q = n + 1，q为最后一个节点下一个节点，即为空，那么此时p即为待删除节点的前一个节点

    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode dummy(0);

        dummy.next = head;

        ListNode * p = &dummy;
        ListNode * q = dummy.next;
        while (n--)
            q = q->next;
        while (q)
        {
            q = q->next;
            p = p->next;
        }

        ListNode * to_delete = p->next;
        p->next = p->next->next;
        delete to_delete;
        return dummy.next;
    }
};


#endif //ALGORITHMS_Q19_REMOVE_NTH_H
