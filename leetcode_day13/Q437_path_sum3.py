# Definition for a binary tree node.
class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None


class Solution:

    def find_path(self, root, sum):
        if root is None:
            return 0
        res = 0
        if root.val == sum:
            res += 1
        res += self.find_path(root.left, sum - root.val)
        res += self.find_path(root.right, sum - root.val)
        return res

    def pathSum(self, root: TreeNode, sum: int) -> int:
        if root is None:
            return 0
        res = 0
        # 包含root的路径
        res += self.find_path(root, sum)

        #不包含root节点的路径
        res += self.pathSum(root.left, sum)
        res += self.pathSum(root.right, sum)
        return res


