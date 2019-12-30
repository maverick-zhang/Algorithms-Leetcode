//
// Created by maverick on 2019/12/27.
//

#ifndef ALGORITHMS_Q86_HPARTITION_LIST_H
#define ALGORITHMS_Q86_HPARTITION_LIST_H


//给定一个链表和一个特定值 x，对链表进行分隔，使得所有小于 x 的节点都在大于或等于 x 的节点之前。
//
//你应当保留两个分区中每个节点的初始相对位置。
//
//示例:
//
//输入: head = 1->4->3->2->5->2, x = 3
//输出: 1->2->2->4->3->5


class Solution {
private:
    struct ListNode {
        int val;
        ListNode *next;
        ListNode(int x) : val(x), next(nullptr) {}
    };
public:
    ListNode* partition(ListNode* head, int x) {

        //使用三个指针p， pre, 和cur,p是小于x的最后一个节点，cur为当前遍历的节点，[p, cur)均为大于等于x的节点
        //对于当前的节点cur,如果其值大于等于x则cur右移，继续遍历，如果小于，则把cur插入到p节点之后
        //pre指针，保持其为cur的前一个节点。

        ListNode * pre = nullptr;
        ListNode * cur = head;
        ListNode * p = nullptr;

        while (cur != nullptr)
        {
            if (cur->val >= x)
            {
                pre = cur;
                cur = cur->next;
            }
            else
            {
                if (pre == nullptr)
                {
                    p = cur;
                    cur = cur->next;
                    continue;
                }

                ListNode * to_insert = cur;

                if (p == nullptr)
                {
                    p = cur;
                    pre->next = cur->next;
                    cur = cur->next;
                    to_insert->next = head;
                    head =  to_insert;
                }
                else
                {
                    pre->next = cur->next;
                    cur = cur->next;
                    to_insert->next = p->next;
                    p->next = to_insert;
                    p = p->next;
                }
            }
        }

        return head;
    }
};

#endif //ALGORITHMS_Q86_HPARTITION_LIST_H
