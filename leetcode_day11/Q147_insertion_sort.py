# Definition for singly-linked list.
# 对链表进行插入排序
# 插入排序的定义: 维持一个有序的序列[l, r]对r+1的节点逐个向前进行比较插入到第一个大于等于的位置
class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None


class Solution:
    def insertionSortList(self, head: ListNode) -> ListNode:
        dummy = ListNode(0)
        dummy.next = head
        pre_cur = dummy
        cur = head
        while cur:
            pre_p = dummy
            p = dummy.next
            while p != cur and p.val <= cur.val:
                pre_p = p
                p = p.next
            if p!= cur:
                pre_cur.next = cur.next
                cur.next = pre_p.next
                pre_p.next = cur
                cur = pre_cur.next
            else:
                pre_cur = cur
                cur = cur.next
        return dummy.next
