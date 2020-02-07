# Definition for singly-linked list.
# 给出两个 非空 的链表用来表示两个非负的整数。其中，它们各自的位数是按照 逆序 的方式存储的，并且它们的每个节点只能存储 一位 数字。
#
# 如果，我们将这两个数相加起来，则会返回一个新的链表来表示它们的和。
#
# 您可以假设除了数字 0 之外，这两个数都不会以 0 开头。



class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None


class Solution:
    def addTwoNumbers(self, l1: ListNode, l2: ListNode) -> ListNode:
        p1, p2 = l1, l2
        dummy = ListNode(float("inf"))
        res = dummy
        carry_flag = 0   # 是否有进位产生
        while p1 or p2 or carry_flag:
            new_node = ListNode(0)
            res.next = new_node
            res = res.next
            num1, num2 = 0, 0
            if p1:
                num1 = p1.val
                p1 = p1.next
            if p2:
                num2 = p2.val
                p2 = p2.next
            total = num1 + num2 + carry_flag
            new_node.val = total % 10
            carry_flag = total // 10
        return dummy.next
