//
// Created by maverick on 2019/12/30.
//

#ifndef ALGORITHMS_Q61_ROTATE_RIGHT_H
#define ALGORITHMS_Q61_ROTATE_RIGHT_H

//给定一个链表，旋转链表，将链表每个节点向右移动 k 个位置，其中 k 是非负数。
//
//示例 1:
//
//输入: 1->2->3->4->5->NULL, k = 2
//输出: 4->5->1->2->3->NULL
//        解释:
//向右旋转 1 步: 5->1->2->3->4->NULL
//        向右旋转 2 步: 4->5->1->2->3->NULL


struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        //先求出链表的长度,当k大于长度时，进行取余运算
        if (head == nullptr or k == 0)
            return head;
        ListNode * p = head;
        int n = 0;
        while (p)
        {
            n ++;
            p = p->next;
        }
        k = k % n;
        if (k == 0)
            return head;
        int end = n - k;
        p = head;
        while (--end)
            p = p->next;
        ListNode * res;
        res = p->next;
        p->next = nullptr;
        p = res;
        while (p->next)
            p = p->next;
        p->next = head;
        return res;
    }
};


#endif //ALGORITHMS_Q61_ROTATE_RIGHT_H
