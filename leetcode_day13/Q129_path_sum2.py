# Definition for a binary tree node.
class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None


class Solution:
    def path(self, root):
        if root is None:
            return []
        res = []
        if root.left is None and root.right is None:
            res.append([root.val])
            return res
        left = self.path(root.left)
        right = self.path(root.right)
        left.extend(right)
        for way in left:
            way.append(root.val)
        return left


    def sumNumbers(self, root: TreeNode) -> int:
        paths = self.path(root)
        res = 0
        for path in paths:
            for i in range(len(path)):
                res += path[i] * 10 ** i
        return res
