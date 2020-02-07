# Definition for singly-linked list.
# 给定一个链表，两两交换其中相邻的节点，并返回交换后的链表。
# 你不能只是单纯的改变节点内部的值，而是需要实际的进行节点交换。
class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None


class Solution:
    def swapPairs(self, head: ListNode) -> ListNode:
        dummy = ListNode(0)
        dummy.next = head
        p = dummy
        while p.next and p.next.next:
            node1, node2 = p.next, p.next.next
            nex = node2.next

            node2.next = node1
            node1.next = nex
            p.next = node2

            p = node1
        return dummy.next