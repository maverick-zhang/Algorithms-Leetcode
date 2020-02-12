# Definition for a binary tree node.
class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

# 方法一：遍历所有的节点
class Solution:
    def countNodes(self, root: TreeNode) -> int:
        if root is None:
            return 0
        return self.countNodes(root.right) + self.countNodes(root.left) + 1


# 方法2：使用二分搜索法
# 假设共有d层，那么第d层的叶子节点如果填充满共有2^(d-1)个
# 前d-1层的所有节点通过等比数列求和可得为2^(d-1)-1个
# 因此题目转换为如何求最后一层叶子节点的个数，假设节点从左到右编号分别为1-2^(d-1)，那么我们只要找到从左到右第一个不存在的节点的编号即可
# 寻找的方式使用二分搜索，第一次去中间的一个节点，那么其遍历的顺序可以根据其编号的大小进行计算
# 比如节点编号分别为1,2,3,4,5,6,7,8我们要找到5号节点，那么其遍历的顺序为root.right.left.left，即每次把5与中间值进行比较
# 第一次中间值为1 + (8-1)//2 为4，即5在右半区，所以第一次为right，第二次比较时区间已经变为了5,6,7,8可以看出5在左半区，因此第二次为left
# 同理第三次也为left
# 可以看出需要确认一个叶节点是否存在需要log(n)的时间复杂度，而利用二分搜索找到这个节点也需要log(n)的时间复杂度
# 因此总时间复杂度为d^2，d为层数
# 二分搜索的步骤为首先找到中间的节点序号，如果其存在，则寻找其右半区的节点
# 如果其不存在则寻找其左半边的节点直到找到的最大存在节点序号和最小不存在节点序号差为1
# 二分起始时left=1, right=2^(d-1)
class Solution2:
    def exists_node(self, node_num, d, root):
        left, right = 1, 2 ** (d-1)
        pivot = left + (right - left) // 2
        p = root
        for i in range(d-1):
            if node_num > pivot:
                p = p.right
                left = pivot + 1
            else:
                p = p.left
                right = pivot - 1
            pivot = left + (right - left) // 2
        return p is not None

    def countNodes(self, root: TreeNode) -> int:
        if root is None:
            return 0
        d = 0
        p = root
        while p:
            p = p.left
            d += 1
        left, right = 1, 2 ** (d-1)
        pivot = left + (right - left) // 2
        while left <= right:
            if self.exists_node(pivot, d, root):
                left = pivot + 1
            else:
                right = pivot - 1
            pivot = left + (right - left) // 2
        return 2 ** (d-1) - 1 + left - 1

