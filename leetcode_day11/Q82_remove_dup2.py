# Definition for singly-linked list.
class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None


class Solution:
    def deleteDuplicates(self, head: ListNode) -> ListNode:
        if head == None:
            return head
        dummy = ListNode(float("inf"))
        dummy.next = head
        cur = head
        nex = head.next
        pre = dummy
        is_dup = False
        while nex:
            if cur.val == nex.val or is_dup:
                # 删除cur节点
                if is_dup and (cur.val != nex.val):
                    is_dup = False
                else:
                    is_dup = True
                pre.next = nex
            else:
                pre = cur
            cur = nex
            nex = cur.next
        if is_dup:
            pre.next = None
        return dummy.next
