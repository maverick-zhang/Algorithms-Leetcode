# Definition for a binary tree node.
class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None


class Solution:
    def pathSum(self, root: TreeNode, sum: int) ->list:
        if root is None:
            return []
        res = []
        if root.left is None and root.right is None:
            if root.val == sum:
                res.append([root.val])
                return res
            return []
        left = self.pathSum(root.left, sum - root.val)
        right = self.pathSum(root.right, sum - root.val)
        left.extend(right)
        for way in left:
            way.insert(0, root.val)
        return left
