# Definition for singly-linked list.
from queue import PriorityQueue
class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None


# 维持一个有k个个元素的优先队列，队列存放的元素是(val, i)为在链表的序号，val为当前链表头结点的大小
class Solution:
    def mergeKLists(self, lists: list) -> ListNode:
        pq = PriorityQueue(len(lists))
        dummy = ListNode(0)
        cur = dummy
        for i in range(len(lists)):
            if lists[i]: 
                pq.put((lists[i].val, i))
        while not pq.empty():
            top = pq.get()[1]
            cur.next = lists[top]
            cur = cur.next
            lists[top] = lists[top].next
            if lists[top]:
                pq.put((lists[top].val, top))
        return dummy.next
