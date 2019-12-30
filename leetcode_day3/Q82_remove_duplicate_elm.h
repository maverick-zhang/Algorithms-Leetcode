//
// Created by maverick on 2019/12/27.
//

#ifndef ALGORITHMS_Q82_REMOVE_DUPLICATE_ELM_H
#define ALGORITHMS_Q82_REMOVE_DUPLICATE_ELM_H

//给定一个排序链表，删除所有含有重复数字的节点，只保留原始链表中 没有重复出现 的数字。
//
//示例 1:
//
//输入: 1->2->3->3->4->4->5
//输出: 1->2->5



struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {

        if (head == nullptr)
            return head;

        ListNode * pre_pre = nullptr;
        ListNode * pre = head;
        ListNode * cur = head->next;

        bool marked = false;

        while (cur != nullptr)
        {
            if (pre->val == cur->val)
            {
                marked = true;
                pre->next = cur->next;
                delete cur;
                cur = pre->next;
            }
            else if (pre->val != cur->val)
            {
                if (marked)
                {
                    if (pre_pre == nullptr)
                    {
                        delete head;
                        head = cur;
                    }
                    else
                    {
                        pre_pre->next = cur;
                        delete pre;
                    }
                    marked = false;
                    pre = cur;
                    cur = cur->next;
                }
                else
                {
                    pre_pre = pre;
                    pre = cur;
                    cur = cur->next;
                }
            }
        }

        if (marked)
        {
            if (pre_pre == nullptr)
            {
                delete head;
                head = nullptr;
            }
            else
                pre_pre->next = nullptr;
        }
        return head;
    }
};

#endif //ALGORITHMS_Q82_REMOVE_DUPLICATE_ELM_H
