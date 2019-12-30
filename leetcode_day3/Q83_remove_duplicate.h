//
// Created by maverick on 2019/12/27.
//

#ifndef ALGORITHMS_Q83_REMOVE_DUPLICATE_H
#define ALGORITHMS_Q83_REMOVE_DUPLICATE_H

//给定一个排序链表，删除所有重复的元素，使得每个元素只出现一次。
//
//示例 1:
//
//输入: 1->1->2
//输出: 1->2

class Solution {
private:
    struct ListNode {
        int val;
        ListNode *next;
        ListNode(int x) : val(x), next(nullptr) {}
    };
public:
    ListNode* deleteDuplicates(ListNode* head) {

        ListNode * cur = head;
        ListNode * pre = nullptr;
        while (cur != nullptr)
        {
            if (pre != nullptr and pre->val == cur->val)
            {
                ListNode * to_delete = cur;
                pre->next = cur->next;
                cur = cur->next;
                delete to_delete;
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

#endif //ALGORITHMS_Q83_REMOVE_DUPLICATE_H
