# Definition for a binary tree node.
class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None


class Solution:
    def binaryTreePaths(self, root: TreeNode) -> list:
        if root is None:
            return []
        if root.left is None and root.right is None:
            return [str(root.val)]
        res = []
        left_list = self.binaryTreePaths(root.left)
        for path in left_list:
            res.append(str(root.val)+"->"+path)
        right_list = self.binaryTreePaths(root.right)
        for path in right_list:
            res.append(str(root.val)+"->"+path)
        return res
