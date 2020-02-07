# Definition for singly-linked list.
class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None


class Solution:
    def deleteNode(self, node):
        """
        :type node: ListNode
        :rtype: void Do not return anything, modify node in-place instead.
        """
        if node is None:
            return
        if node.next is None:
            del node
        nex = node.next
        node.val = nex.val
        node.next = nex.next
        return