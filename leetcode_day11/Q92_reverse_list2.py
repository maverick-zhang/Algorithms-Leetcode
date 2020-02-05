# Definition for singly-linked list.
class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None
# 输入: 1->2->3->4->5->NULL, m = 2, n = 4
# 输出: 1->4->3->2->5->NULL
# 反转从位置 m 到 n 的链表。请使用一趟扫描完成反转。
class Solution:
    def reverseBetween(self, head: ListNode, m: int, n: int) -> ListNode:
        i = 1
        pre_reverse = None # 代表反转区间前面的一个节点
        cur = head
        while i < m:
            pre_reverse = cur
            cur = cur.next
            i += 1
        pre = None
        while i < n:
            next = cur.next
            cur.next = pre
            pre = cur
            cur = next
            i += 1
        if cur == head:
            return head
        if pre_reverse is not None:
            pre_reverse.next.next = cur.next
            pre_reverse.next = cur
            cur.next = pre
            return head
        else:
            head.next = cur.next
            cur.next = pre
            return cur
