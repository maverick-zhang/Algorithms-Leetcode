# Definition for a binary tree node.
class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None


class Solution:
    # BST的中序遍历是生序序列
    def kthSmallest(self, root: TreeNode, k: int) -> int:
        stack = []
        p = root
        while p or stack:
            if p:
                stack.append(p)
                p = p.left
                continue
            p = stack.pop()
            k -= 1
            if k == 0:
                return p.val
            p = p.right
