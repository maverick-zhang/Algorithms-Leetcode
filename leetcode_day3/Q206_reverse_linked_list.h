//
// Created by maverick on 2019/12/27.
//

#ifndef ALGORITHMS_Q206_REVERSE_LINKED_LIST_H
#define ALGORITHMS_Q206_REVERSE_LINKED_LIST_H

//反转一个单链表。
//
//示例:
//
//输入: 1->2->3->4->5->NULL
//        输出: 5->4->3->2->1->NULL




class Solution {
private:
    struct ListNode {
        int val;
        ListNode *next;
        ListNode(int x) : val(x), next(nullptr) {}
    };
public:
    ListNode* reverseList(ListNode* head) {

        if (head == nullptr)
            return head;

        ListNode * pre = nullptr;
        ListNode * cur = head;
        ListNode * next = cur->next;

        while (cur != nullptr)
        {
            cur->next = pre;
            pre = cur;
            cur = next;
            next = (next == nullptr)? nullptr: next->next;
        }

        return pre;
    }
};


#endif //ALGORITHMS_Q206_REVERSE_LINKED_LIST_H
