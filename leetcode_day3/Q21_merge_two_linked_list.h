//
// Created by maverick on 2019/12/27.
//

#ifndef ALGORITHMS_Q21_MERGE_TWO_LINKED_LIST_H
#define ALGORITHMS_Q21_MERGE_TWO_LINKED_LIST_H

//将两个有序链表合并为一个新的有序链表并返回。新链表是通过拼接给定的两个链表的所有节点组成的。 
//
//示例：
//
//输入：1->2->4, 1->3->4
//输出：1->1->2->3->4->4
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {

        ListNode * cur_l1 = l1;
        ListNode * cur_l2 = l2;
        ListNode * res = nullptr;
        ListNode * cur_res = nullptr;
        ListNode * pre = nullptr;

        while (cur_l1 != nullptr or cur_l2 != nullptr)
        {
            if (cur_l1 == nullptr)
            {
                cur_res = cur_l2;
                cur_l2 = cur_l2->next;
            }
            else if (cur_l2 == nullptr)
            {
                cur_res = cur_l1;
                cur_l1 = cur_l1->next;
            }
            else
            {
                if (cur_l1->val<cur_l2->val)
                {
                    cur_res = cur_l1;
                    cur_l1 = cur_l1->next;
                }
                else
                {
                    cur_res = cur_l2;
                    cur_l2 = cur_l2->next;
                }
            }

            if (pre == nullptr)
                res = pre = cur_res;
            else
            {
                pre->next = cur_res;
                pre = cur_res;
            }
        }
        return res;

    }
};

#endif //ALGORITHMS_Q21_MERGE_TWO_LINKED_LIST_H
