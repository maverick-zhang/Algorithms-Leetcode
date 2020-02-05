# Definition for singly-linked list.
class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None

class Solution:
    def oddEvenList(self, head: ListNode) -> ListNode:
        if head == None or head.next == None:
            return head
        last_odd = head
        first_even = head.next
        pre = head.next
        cur = head.next.next
        while cur:
            pre.next = cur.next
            last_odd.next = cur
            last_odd = last_odd.next
            last_odd.next = first_even
            if pre.next:
                cur = pre.next.next
                pre = pre.next
            else:
                break
        return head


if __name__ == '__main__':
    head = ListNode(1)
    i = 2
    cur = head
    while i <= 6:
        cur.next = ListNode(i)
        cur = cur.next
        i += 1
    s = Solution()
    s.oddEvenList(head)
    print(1)

