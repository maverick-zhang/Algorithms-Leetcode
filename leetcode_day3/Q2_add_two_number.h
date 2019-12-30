//
// Created by maverick on 2019/12/27.
//

#ifndef ALGORITHMS_Q2_ADD_TWO_NUMBER_H
#define ALGORITHMS_Q2_ADD_TWO_NUMBER_H


//给出两个 非空 的链表用来表示两个非负的整数。其中，它们各自的位数是按照 逆序 的方式存储的，并且它们的每个节点只能存储 一位 数字。
//
//如果，我们将这两个数相加起来，则会返回一个新的链表来表示它们的和。
//
//您可以假设除了数字 0 之外，这两个数都不会以 0 开头。
//
//示例：
//
//输入：(2 -> 4 -> 3) + (5 -> 6 -> 4)
//输出：7 -> 0 -> 8
//原因：342 + 465 = 807

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {

        ListNode * cur_l1 = l1;
        ListNode * cur_l2 = l2;
        ListNode  * res = nullptr;
        ListNode * cur_res = res;

        int carry = 0;
        int digit = 0;
        while (cur_l1 != nullptr or cur_l2 != nullptr or carry)
        {
            int temp;
            if (res == nullptr)
                res = cur_res = new ListNode(0);
            else
            {
                cur_res->next = new ListNode(0);
                cur_res = cur_res->next;
            }
            if (cur_l1 != nullptr and cur_l2 != nullptr)
                temp = carry + cur_l1->val + cur_l2->val;
            else if (cur_l1 == nullptr and cur_l2 == nullptr)
            {
                cur_res->val = carry;
                break;
            }
            else
            {
                if (cur_l1 == nullptr)
                    temp = carry  + cur_l2->val;
                else
                    temp = carry + cur_l1->val;
            }
            digit = temp % 10;
            carry = temp / 10;
            cur_res->val = digit;
            cur_l1 = (cur_l1 != nullptr)?(cur_l1->next): nullptr;
            cur_l2 = (cur_l2 != nullptr)?(cur_l2->next): nullptr;
        }

        return res;
    }
};


#endif //ALGORITHMS_Q2_ADD_TWO_NUMBER_H
