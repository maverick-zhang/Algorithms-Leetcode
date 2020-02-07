# Definition for singly-linked list.
class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None


class Solution:
    def mergeTwoLists(self, l1: ListNode, l2: ListNode) -> ListNode:
        dummy = ListNode(0)
        res = dummy
        p1, p2 = l1, l2
        while p1 or p2:
            if p1 is None:
                res.next = p2
                return dummy.next
            if p2 is None:
                res.next = p1
                return dummy.next
            if p1.val <= p2.val:
                res.next = p1
                p1 = p1.next
            else:
                res.next = p2
                p2 = p2.next
            res = res.next
        return dummy.next
