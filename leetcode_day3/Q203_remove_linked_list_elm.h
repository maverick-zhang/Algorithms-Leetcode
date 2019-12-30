//
// Created by maverick on 2019/12/27.
//

#ifndef ALGORITHMS_Q203_REMOVE_LINKED_LIST_ELM_H
#define ALGORITHMS_Q203_REMOVE_LINKED_LIST_ELM_H

//删除链表中等于给定值 val 的所有节点。
//
//示例:
//
//输入: 1->2->6->3->4->5->6, val = 6
//输出: 1->2->3->4->5

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        ListNode * cur = head;
        ListNode * pre = nullptr;

        while (cur != nullptr)
        {
            if (cur->val == val)
            {
                if (pre == nullptr)
                {
                    cur = cur->next;
                    delete head;
                    head = cur;
                }
                else
                {
                    pre->next = cur->next;
                    delete cur;
                    cur = pre->next;
                }
            }
            else
            {
                pre = cur;
                cur = cur->next;
            }
        }
        return head;
    }
};

#endif //ALGORITHMS_Q203_REMOVE_LINKED_LIST_ELM_H
