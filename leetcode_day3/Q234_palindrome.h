//
// Created by maverick on 2019/12/30.
//

#ifndef ALGORITHMS_Q234_PALINDROME_H
#define ALGORITHMS_Q234_PALINDROME_H

#include <stack>
//请判断一个链表是否为回文链表。
//
//示例 1:
//
//输入: 1->2
//输出: false
//O(n)时间复杂度，O(1)空间复杂度

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};
using namespace std;
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        stack<ListNode *> st;
        ListNode * p = head;
        int n = 0;
        while (p != nullptr)
        {
            st.push(p);
            p = p->next;
            n ++;
        }

        p = head;
        for (int i = 0; i < n/2; ++i) {
            if (p->val != st.top()->val)
                return false;
            st.pop();
            p = p->next;
        }
        return true;

    }
};

#endif //ALGORITHMS_Q234_PALINDROME_H
