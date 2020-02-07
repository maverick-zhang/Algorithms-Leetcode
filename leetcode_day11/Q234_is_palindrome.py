# Definition for singly-linked list.
class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None

# 时间复杂度O(n),空间复杂度O(1)
class Solution:
    def isPalindrome(self, head: ListNode) -> bool:
        i, p = 0, head
        while p:
            i += 1
            p = p.next
        if i < 2:
            return True
        i = i // 2
        # 定位到倒数第i个元素，然后把该部分链表翻转
        dummy = ListNode(0)
        dummy.next = head
        p = q = dummy
        for i in range(i):
            q = q.next
        while q:
            p, q = p.next, q.next
        nex = p.next
        p.next = None
        while nex:
            new_nex = nex.next
            nex.next = p
            p = nex
            nex = new_nex
        q = head
        while p:
            if p.val != q.val:
                return False
            p, q = p.next, q.next
        return True
