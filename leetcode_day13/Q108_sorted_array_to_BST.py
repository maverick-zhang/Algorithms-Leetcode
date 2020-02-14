# Definition for a binary tree node.
class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None


class Solution:
    # 给定有序数组: [-10,-3,0,5,9],
    # 找到中间点，作为根节点，左半区构建左平衡子树，右半区构建右平衡子树
    def sortedArrayToBST(self, nums) -> TreeNode:
        if not nums:
            return None
        left, right = 0, len(nums) - 1
        pivot = left + (right-left)//2
        root = TreeNode(nums[pivot])
        root.left = self.sortedArrayToBST(nums[0:pivot])
        root.right = self.sortedArrayToBST(nums[pivot+1:])
        return root