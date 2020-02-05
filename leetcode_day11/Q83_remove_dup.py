# Definition for singly-linked list.
class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None


class Solution:
    def deleteDuplicates(self, head: ListNode) -> ListNode:
        dummy = ListNode(float("inf"))
        dummy.next = head
        pre = dummy
        cur = head
        while cur:
            if cur.val == pre.val:
                # 删除cur
                pre.next = cur.next
            else:
                pre = cur
            cur = cur.next
        return dummy.next


