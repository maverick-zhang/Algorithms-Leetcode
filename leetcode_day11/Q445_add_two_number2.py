# Definition for singly-linked list.

# 给定两个非空链表来代表两个非负整数。数字最高位位于链表开始位置。它们的每个节点只存储单个数字。将这两数相加会返回一个新的链表。
# 你可以假设除了数字 0 之外，这两个数字都不会以零开头。
# 输入: (7 -> 2 -> 4 -> 3) + (5 -> 6 -> 4)
# 输出: 7 -> 8 -> 0 -> 7

class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None

# 思路先把两个数字取出来，进行相加之后放到新的链表中
class Solution:
    def addTwoNumbers(self, l1: ListNode, l2: ListNode) -> ListNode:
        p1, p2 = l1, l2
        num1, num2 = 0, 0
        while p1:
            num1 = num1 * 10 + p1.val
            p1 = p1.next
        while p2:
            num2 = num2 * 10 + p2.val
            p2 = p2.next
        res_num = num1 + num2
        num_string = str(res_num)
        dummy = ListNode(float("inf"))
        res = dummy
        for ch in num_string:
            new_node = ListNode(eval(ch))
            res.next = new_node
            res = res.next
        return dummy.next

