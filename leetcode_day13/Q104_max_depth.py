# Definition for a binary tree node.
class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None


class Solution:
    def maxDepth(self, root: TreeNode) -> int:
        if root is None:
            return 0
        left_dept = self.maxDepth(root.left)
        right_dept = self.maxDepth(root.right)
        return max(left_dept, right_dept) + 1