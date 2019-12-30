//
// Created by maverick on 2019/12/30.
//

#ifndef ALGORITHMS_Q24_SWAP_PAIRS_H
#define ALGORITHMS_Q24_SWAP_PAIRS_H

//给定一个链表，两两交换其中相邻的节点，并返回交换后的链表。
//
//你不能只是单纯的改变节点内部的值，而是需要实际的进行节点交换。

//示例:
//
//给定 1->2->3->4, 你应该返回 2->1->4->3.

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {

        //使用四个指针，pre->node1->node2->next，在遍历的过程中，pre->node2, node2->node1,node1->next,最后更新pre

        if (head == nullptr)
            return head;

        auto * dummy = new ListNode(0);
        dummy->next = head;

        ListNode * pre = dummy;
        ListNode * node1 = nullptr;
        ListNode * node2 = nullptr;
        ListNode * next = nullptr;

        while (pre->next != nullptr and pre->next->next != nullptr)
        {
            node1 = pre->next;
            node2= node1->next;
            next = node2->next;


            pre->next = node2;
            node2->next = node1;
            node1->next = next;
            pre = node1;

        }

        head = dummy->next;
        delete dummy;
        return head;
    }
};



#endif //ALGORITHMS_Q24_SWAP_PAIRS_H
