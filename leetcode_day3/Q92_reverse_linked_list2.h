//
// Created by maverick on 2019/12/27.
//

#ifndef ALGORITHMS_Q92_REVERSE_LINKED_LIST2_H
#define ALGORITHMS_Q92_REVERSE_LINKED_LIST2_H

//反转从位置 m 到 n 的链表。请使用一趟扫描完成反转。
//
//说明:
//1 ≤ m ≤ n ≤ 链表长度。
//
//示例:
//
//输入: 1->2->3->4->5->NULL, m = 2, n = 4
//输出: 1->4->3->2->5->NULL

class Solution {
private:
    struct ListNode {
        int val;
        ListNode *next;
        ListNode(int x) : val(x), next(nullptr) {}
    };
public:
    ListNode* reverseBetween(ListNode* head, int m, int n) {

        if (head == nullptr or m == n)
            return head;

        ListNode * pre = nullptr;
        ListNode * cur = head;
        ListNode * pre_cur = nullptr;
        ListNode * next = nullptr;

        if (m != 1)
        {
            pre = head;
            for (int i = 1; i < m - 1; ++i)
                pre = pre->next;
        }
        if (pre != nullptr)
            cur = pre->next;
        next = cur->next;

        for (int j = m; j <= n; ++j) {
            cur->next = pre_cur;
            pre_cur = cur;
            cur = next;
            next = (next == nullptr)? nullptr:next->next;
        }
        if (pre == nullptr)
        {
            head->next = cur;
            return pre_cur;
        }
        else
        {
            pre->next->next = cur;
            pre->next = pre_cur;
            return head;
        }

    }
};



#endif //ALGORITHMS_Q92_REVERSE_LINKED_LIST2_H
