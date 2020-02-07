# Definition for singly-linked list.
# 给你一个链表，每 k 个节点一组进行翻转，请你返回翻转后的链表。
# k 是一个正整数，它的值小于或等于链表的长度。
# 如果节点总数不是 k 的整数倍，那么请将最后剩余的节点保持原有顺序。
# 示例 :
# 给定这个链表：1->2->3->4->5
# 当 k = 2 时，应当返回: 2->1->4->3->5
# 当 k = 3 时，应当返回: 3->2->1->4->5
class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None


class Solution:
    def reverseKGroup(self, head: ListNode, k: int) -> ListNode:
        dummy = ListNode(0)
        dummy.next = head
        pre = dummy
        cur = head
        while cur:
            first = cur
            i = 1
            while cur and i < k:
                cur = cur.next
                i += 1
            if i < k or not cur:
                break
            last = cur
            cur = cur.next

            pre.next = last
            pre_p = first
            p = first.next
            while p != last:
                after_p = p.next
                p.next = pre_p
                pre_p = p
                p = after_p
            p.next = pre_p
            first.next = cur
            pre = first
        return dummy.next



