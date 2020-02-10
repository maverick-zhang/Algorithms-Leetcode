# Definition for a binary tree node.
from queue import Queue
class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None


# 先右后左层序遍历，每层的第一个节点即组成右视图
class Solution:
    def rightSideView(self, root: TreeNode) -> list:
        res = []
        if root is None:
            return res

        que = Queue()
        que.put((root, 0))
        while not que.empty():
            node = que.get()
            if len(res) == node[1]:
                res.append(node[0].val)
            if node[0].right:
                que.put((node[0].right, node[1]+1))
            if node[0].left:
                que.put((node[0].left, node[1]+1))
        return res