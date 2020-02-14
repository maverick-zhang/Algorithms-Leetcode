# Definition for a binary tree node.
class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None


class Solution:
    def isValidBST(self, root: TreeNode) -> bool:
        if root is None:
            return True
        p = root.left
        while p:
            if p.val >= root.val:
                return False
            p = p.right
        p = root.right
        while p:
            if p.val <= root.val:
                return False
            p = p.left
        return  self.isValidBST(root.left) and self.isValidBST(root.right)