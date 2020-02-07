# Definition for singly-linked list.
class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None


class Solution:
    def removeElements(self, head: ListNode, val: int) -> ListNode:
        dummy = ListNode(float("inf"))
        dummy.next = head
        p = head
        pre = dummy
        while p:
            if p.val == val:
                pre.next = p.next
            else:
                pre = p
            p = p.next
        return dummy.next