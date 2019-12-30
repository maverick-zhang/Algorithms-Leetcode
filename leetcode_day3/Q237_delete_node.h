//
// Created by maverick on 2019/12/30.
//

#ifndef ALGORITHMS_Q237_DELETE_NODE_H
#define ALGORITHMS_Q237_DELETE_NODE_H

//请编写一个函数，使其可以删除某个链表中给定的（非末尾）节点，你将只被给定要求被删除的节点。
//输入: head = [4,5,1,9], node = 5
//输出: [4,1,9]
//解释: 给定你链表中值为 5 的第二个节点，那么在调用了你的函数之后，该链表应变为 4 -> 1 -> 9.

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    //把下个节点的值赋给当前节点,然后删除下一个节点

    void deleteNode(ListNode* node) {
        ListNode * to_delete = node->next;
        node->val = node->next->val;
        node->next = node->next->next;
        delete to_delete;
    }
};





#endif //ALGORITHMS_Q237_DELETE_NODE_H
