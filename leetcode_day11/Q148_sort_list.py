# Definition for singly-linked list.
class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None

# 自顶向下的归并排序: 把区间拆分为左右两部分，然后对左右两个搬去进行排序，排序之后的左右两半部分再进行归并
# 对左右两个半区递归调用排序，直到每个区间只有一个元素，单个元素始终是有序的，因此算法由此向上回溯不断进行归并
# 但是由于链表不具有随机读取性，因此无法直接进行拆分操作
# 自底向上的排序算法:先每一个节点进行两两归并，然后逐步扩大
class Solution:
    def sortList(self, head: ListNode):
        if head is None:
            return head
        head_list = []
        p = head
        while p:
            nex = p.next
            p.next = None
            head_list.append(p)
            p = nex
        dummy = ListNode(0)
        while len(head_list) > 1:
            new_list = []
            i = 0
            while i + 1< len(head_list):
                l1 = head_list[i]
                l2 = head_list[i+1]
                p = dummy
                while l1 or l2:
                    if l1 is None:
                        p.next = l2
                        break
                    if l2 is None:
                        p.next = l1
                        break
                    if l1.val <= l2.val:
                        p.next = l1
                        l1 = l1.next
                    else:
                        p.next = l2
                        l2 = l2.next
                    p = p.next
                new_list.append(dummy.next)
                i += 2
            if i == len(head_list)-1:
                new_list.append(head_list[-1])
            head_list = new_list
        print(1)
        return head_list[0]


if __name__ == '__main__':
    head = ListNode(4)
    p = head
    for i in range(3, 0, -1):
        p.next = ListNode(i)
        p = p.next
    s = Solution()
    s.sortList(head)
