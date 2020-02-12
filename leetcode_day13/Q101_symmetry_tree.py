# Definition for a binary tree node.
class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None


class Solution:
    def __is_sym(self, left, right):
        if not left and not right:
            return True
        if left and right:
            if left.val != right.val:
                return False
            else:
                return self.__is_sym(left.left, right.right) and self.__is_sym(left.right, right.left)
        else:
            return False

    def isSymmetric(self, root: TreeNode) -> bool:
        if root is None:
            return True
        return self.__is_sym(root.left, root.right)