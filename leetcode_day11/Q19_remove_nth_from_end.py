# Definition for singly-linked list.
class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None


class Solution:
    def removeNthFromEnd(self, head: ListNode, n: int) -> ListNode:
        """

        :param head:
        :param n:
        :return:
        """
        dummy = ListNode(0)
        dummy.next = head
        p = dummy
        q = dummy
        for i in range(n+1):
            q = q.next
        while q is not None:
            p = p.next
            q = q.next
        del_node = p.next
        p.next = del_node.next
        return dummy.next

