//
// Created by maverick on 2020/1/1.
//

#ifndef ALGORITHMS_Q23_MERGE_K_LISTS_H
#define ALGORITHMS_Q23_MERGE_K_LISTS_H

#include <vector>
#include <queue>

//合并 k 个排序链表，返回合并后的排序链表。请分析和描述算法的复杂度。
//
//示例:
//
//输入:
//[
//  1->4->5,
//  1->3->4,
//  2->6
//]
//输出: 1->1->2->3->4->4->5->6


 struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(nullptr) {}
  };

using namespace std;

//把k个有序链表的头结点放到优先队列中，每次取出最小的那个，并把该链表的下一节点放入到优先队列中.

class Solution
{
public:
    ListNode * mergeKLists(vector<ListNode*> & lists)
    {
        ListNode dummy(0);
        ListNode *p = &dummy;
        priority_queue<pair<int, ListNode *>, vector<pair<int, ListNode*>>, greater<pair<int, ListNode*>>> pri_que;
        for (int i = 0; i < lists.size(); ++i)
        {
          if (lists[i])
              pri_que.push(make_pair(lists[i]->val, lists[i]));
        }

        ListNode * cur;
        while (!pri_que.empty())
        {
            cur = pri_que.top().second;
            p->next = cur;
            p = p->next;
            pri_que.pop();
            if (cur->next)
                pri_que.push(make_pair(cur->next->val, cur->next));
        }

        return dummy.next;
    }
};


//class Solution {
//public:
//    ListNode* mergeKLists(vector<ListNode*>& lists) {
//
//        ListNode dummy = ListNode(0);
//        ListNode * p = &dummy;
//
//        while (true)
//        {
//            int min;
//            ListNode * cur = nullptr;
//            int i = 0;
//            int index = 0;
//            for (; i < lists.size(); ++i)
//            {
//                if (lists[i])
//                {
//                    if (!cur)
//                    {
//                        min = lists[i]->val;
//                        cur = lists[i];
//                        index = i;
//                    }
//                    else
//                    {
//                        if (lists[i]->val < min)
//                        {
//                            min = lists[i]->val;
//                            cur = lists[i];
//                            index = i;
//                        }
//                    }
//
//                }
//            }
//            if (!cur)
//                break;
//            p->next = cur;
//            lists[index] = lists[index]->next;
//            p = p->next;
//        }
//
//        return dummy.next;
//
//    }
//};


#endif //ALGORITHMS_Q23_MERGE_K_LISTS_H
