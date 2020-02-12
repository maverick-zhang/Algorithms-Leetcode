# Definition for a binary tree node.
class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

# 平衡二叉树，左右两个子树的高度差不超过1
class Solution:
    def length(self, root):
        if root is None:
            return 0
        return max(self.length(root.right), self.length(root.left)) + 1

    def __is_bal(self, left, right) -> bool:
        if not left and not right:
            return True
        left_len = self.length(left)
        right_len = self.length(right)
        if abs(right_len - left_len) > 1:
            return False
        if not left and self.__is_bal(right.left, right.right):
            return True
        if not right and self.__is_bal(left.left, left.right):
            return True
        return self.__is_bal(right.left, right.right) and self.__is_bal(left.right, left.left)


    def isBalanced(self, root: TreeNode) -> bool:
        if root is None:
            return True
        return self.__is_bal(root.left, root.right)