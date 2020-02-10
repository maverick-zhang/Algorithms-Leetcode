class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None


class Solution:
    def traverse(self, node, record):
        if node is None:
            return
        self.traverse(node.left, record)
        self.traverse(node.right, record)
        record.append(node.val)


    def postorderTraversal(self, root: TreeNode) -> list:
        res = []
        self.traverse(root, res)
        return res