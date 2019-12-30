//
// Created by maverick on 2019/12/27.
//

#ifndef ALGORITHMS_Q328_ODD_EVEN_LINKED_LIST_H
#define ALGORITHMS_Q328_ODD_EVEN_LINKED_LIST_H

//给定一个单链表，把所有的奇数节点和偶数节点分别排在一起。请注意，这里的奇数节点和偶数节点指的是节点编号的奇偶性，而不是节点的值的奇偶性。
//
//请尝试使用原地算法完成。你的算法的空间复杂度应为 O(1)，时间复杂度应为 O(nodes)，nodes 为节点总数。
//
//示例 1:
//
//输入: 1->2->3->4->5->NULL
//输出: 1->3->5->2->4->NULL

class Solution {
private:
    struct ListNode {
        int val;
        ListNode *next;
        ListNode(int x) : val(x), next(nullptr) {}
    };
public:
    ListNode* oddEvenList(ListNode* head) {

        if (head == nullptr or head->next == nullptr)
            return head;
        ListNode * cur = head->next->next;
        ListNode * pre_cur = head->next;

        ListNode * odd_tail = head;
        ListNode * even_tail = head->next;
        while (cur != nullptr)
        {
            pre_cur->next = cur->next;
            cur->next = odd_tail->next;
            odd_tail->next = cur;
            odd_tail = odd_tail->next;
            cur = pre_cur->next;
            if (cur == nullptr or cur->next == nullptr)
                break;
            pre_cur = cur;
            cur = cur->next;
        }
        return head;
    }
};




#endif //ALGORITHMS_Q328_ODD_EVEN_LINKED_LIST_H
