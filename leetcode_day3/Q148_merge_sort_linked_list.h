//
// Created by maverick on 2019/12/30.
//

#ifndef ALGORITHMS_Q148_MERGE_SORT_LINKED_LIST_H
#define ALGORITHMS_Q148_MERGE_SORT_LINKED_LIST_H


//在 O(n log n) 时间复杂度和常数级空间复杂度下，对链表进行排序。
//
//示例 1:
//
//输入: 4->2->1->3
//输出: 1->2->3->4

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

//使用自底向上的归并排序
//首先两两元素进行归并直到链表尾部，然后扩大，每四个元素进行归并直到归并的范围超过链表的长度

class Solution {
private:

    //对两个已排序链表进行归并,返回归后的链表头部
    ListNode * merge(ListNode * l1, ListNode * l2)
    {
        ListNode dummy(0);
        ListNode * p = &dummy;
        while (l1 and l2)
        {
            if (l1->val < l2->val)
            {
                p->next = l1;
                l1 = l1->next;
            }
            else
            {
                p->next = l2;
                l2 = l2->next;
            }
            p = p->next;
        }
        p->next = (l1)?l1:l2;
        return dummy.next;
    }


    //对一个链表进行切割,切去前n个节点成为一个单独的链表，并返回剩余链表的头节点
    ListNode * cut(ListNode * head, int n)
    {
        ListNode * p = head;
        while (p and --n)
            p = p->next;
        if (!p)
            return nullptr;
        ListNode * remain = p->next;
        p->next = nullptr;
        return remain;
    }


public:
    ListNode* sortList(ListNode* head) {

        //首先遍历链表计算总长度
        ListNode dummy(0);
        dummy.next = head;
        ListNode * p = head;
        int n = 0;
        while (p)
        {
            n ++;
            p = p->next;
        }

        int size = 1;
        for(size = 1;size<=n;size*=2)
        {
            //cur为下一组归并列表对的起点,tail为已经完成归并的链表的尾节点
            auto cur = dummy.next;
            auto tail = &dummy;
            ListNode * right = nullptr;
            ListNode * left = nullptr;

            while (cur)
            {
                left = cur;
                right = cut(cur, size);
                cur = cut(right, size);
                tail->next = merge(left, right);
                while (tail->next)
                    tail = tail->next;
            }
        }
        return dummy.next;
    }
};

#endif //ALGORITHMS_Q148_MERGE_SORT_LINKED_LIST_H
