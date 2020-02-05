# Definition for singly-linked list.
class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None

class Solution:
    def partition(self, head: ListNode, x: int) -> ListNode:
        dummy = ListNode(float("inf"))
        dummy.next = head
        last_lt = dummy   # 最后一个小于x的节点
        first_gte = None  # 第一个大于等于x的节点
        pre = dummy
        cur = head
        while cur:
            if cur.val < x:
                if pre == dummy or pre.val < x:
                    pre = cur
                    last_lt = cur
                    cur = cur.next
                else:
                    pre.next = cur.next
                    last_lt.next = cur
                    last_lt = last_lt.next
                    last_lt.next = first_gte
                    cur = pre.next
            else:
                if first_gte is None:
                    first_gte = cur
                pre = cur
                cur = cur.next
        return dummy.next




