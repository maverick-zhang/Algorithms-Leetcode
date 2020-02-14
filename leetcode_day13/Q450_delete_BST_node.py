# Definition for a binary tree node.
class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

# 删除二叉树的节点，要求时间复杂度为O(h),h为树的高度
class Solution:
    def deleteNode(self, root: TreeNode, key: int) -> TreeNode:
        # 待删除节点的父节点和待删除的节点
        p_node = d_node = None
        cur_node = root
        while cur_node:
            if cur_node.val == key:
                d_node = cur_node
                break
            p_node = cur_node
            if cur_node.val > key:
                cur_node = cur_node.left
            else:
                cur_node = cur_node.right
        if not d_node:
            return root
        # 如果待删除的节点是叶节点
        if d_node.left is None and d_node.right is None:
            if not p_node:
                return None
            if p_node.left is d_node:
                p_node.left = None
            else:
                p_node.right = None
            return root

        # 待删除的节点没有左子树
        if not d_node.left:
            if not p_node:
                return d_node.right
            if p_node.left is d_node:
                p_node.left = d_node.right
            else:
                p_node.right = d_node.right
            return root

        # 待删除的节点没有右子树
        if not d_node.right:
            if not p_node:
                return d_node.left
            if p_node.right is d_node:
                p_node.right = d_node.left
            else:
                p_node.left = d_node.left
            return root

        # 待删除的节点不是叶子节点
        # 寻找需要移动的节点，这里寻找待删除节点右左子树的最右叶节点
        m_node = d_node.left
        p_m_node = None
        while m_node and m_node.right:
            p_m_node = m_node
            m_node = m_node.right

        if p_m_node:
            if p_m_node.left is m_node:
                p_m_node.left = m_node.left
            else:
                p_m_node.right = m_node.left
            m_node.left = d_node.left
        m_node.right = d_node.right
        if not p_node:
            return m_node
        else:
            if p_node.left is d_node:
                p_node.left = m_node
            else:
                p_node.right = m_node
            return root


if __name__ == '__main__':
    root = TreeNode(5)
    root.left = TreeNode(3)
    root.left.left = TreeNode(2)
    root.left.right = TreeNode(4)
    root.right = TreeNode(6)
    root.right.right = TreeNode(7)

    s = Solution()
    s.deleteNode(root, 3)


