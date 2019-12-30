//
// Created by maverick on 2019/12/30.
//

#ifndef ALGORITHMS_Q147_INSERTION_SORT_H
#define ALGORITHMS_Q147_INSERTION_SORT_H

//对链表进行插入排序。

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:


    ListNode* insertionSortList(ListNode* head) {
        if (head == nullptr or head->next == nullptr)
            return head;

        ListNode * dummy = new ListNode(0);
        dummy->next = head;
        ListNode * left = head;
        ListNode * cur = head->next;
        ListNode * right = head;
        ListNode * p = nullptr;
        ListNode * pre_p = nullptr;


        while (cur != nullptr)
        {
            if (cur->val >= right->val)
            {
                right = right->next;
                cur = cur->next;
                continue;
            }
            p = left;
            pre_p = dummy;
            while (cur->val >= p->val)
            {
                pre_p = p;
                p = p->next;
            }

            right->next = cur->next;
            pre_p->next = cur;
            cur->next = p;

            cur = right->next;
            left = dummy->next;
        }

        delete dummy;
        return left;

    }
};


#endif //ALGORITHMS_Q147_INSERTION_SORT_H
