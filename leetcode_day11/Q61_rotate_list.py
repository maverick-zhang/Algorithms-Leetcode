# Definition for singly-linked list.
class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None


class Solution:
    def rotateRight(self, head: ListNode, k: int):
        if head is None or k == 0:
            return head
        i = 0
        p = head
        while p:
            i += 1
            p = p.next
        k = k % i
        if k == 0:
            return head
        dummy = ListNode(0)
        dummy.next = head
        p = q = dummy
        for i in range(k+1):
            q = q.next
        while q:
            if q.next is None:
                end = q
            p = p.next
            q = q.next
        head = p.next
        p.next = None
        end.next = dummy.next
        return head
