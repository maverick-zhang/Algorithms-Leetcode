# Definition for singly-linked list.
class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None

# 思路：先把链表进行拆分,后半部分放入列表中实现随机读取
class Solution:
    def reorderList(self, head: ListNode) -> None:
        """
        Do not return anything, modify head in-place instead.
        """
        i = 0
        p = head
        while p:
            i += 1
            p = p.next
        if i < 3:
            return
        k = i // 2 if (i % 2 == 0) else (i+1) // 2

        cur = head
        for i in range(k):
            cur = cur.next

        nodes = []
        while cur:
            nex = cur.next
            cur.next = None
            nodes.append(cur)
            cur = nex

        p = head
        for i in range(len(nodes)-1, -1, -1):
            nex = p.next
            p.next = nodes[i]
            p.next.next = nex
            p = nex
        if p.next is not None:
            p.next = None

        # pre.next = None
        # p = head
        # while cur:
        #     p_nex = p.next
        #     p.next = cur
        #     cur_nex = cur.next
        #     cur.next = p_nex
        #     cur = cur_nex
        #     p = p_nex



