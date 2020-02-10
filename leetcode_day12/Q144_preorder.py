# Definition for a binary tree node.
class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None


class Solution:
    def traverse(self, node, record):
        if node is None:
            return
        record.append(node.val)
        self.traverse(node.left, record)
        self.traverse(node.right, record)

    def preorderTraversal(self, root: TreeNode) -> list:
        res = []
        self.traverse(root, res)
        return res
