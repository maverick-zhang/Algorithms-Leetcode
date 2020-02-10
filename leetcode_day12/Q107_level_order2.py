from queue import Queue
# Definition for a binary tree node.
class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None


class Solution:
    def levelOrderBottom(self, root: TreeNode) -> list:
        res = []
        if root is None:
            return res

        que = Queue()
        que.put((root, 0))
        while not que.empty():
            node = que.get()
            if len(res) == node[1]:
                res.append([])
            res[node[1]].append(node[0].val)
            if node[0].left:
                que.put((node[0].left, node[1]+1))
            if node[0].right:
                que.put((node[0].right, node[1]+1))
        res.reverse()
        return res