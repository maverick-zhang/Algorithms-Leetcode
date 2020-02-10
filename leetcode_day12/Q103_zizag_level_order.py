from queue import Queue
#       3
#      / \
#     9  20
#        / \
#       15   7
# 返回锯齿形层次遍历如下：
#
# [
#     [3],
#     [20,9],
#     [15,7]
# ]


# Definition for a binary tree node.
class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Solution:
    def zigzagLevelOrder(self, root: TreeNode) -> list:
        res = []
        if root is None:
            return res
        que = Queue()
        que.put((root, 0))
        stack = []
        i = 0
        while not que.empty() or stack:
            if not que.empty():
                front = que.get()
                if front[1] == len(res):
                    res.append([])
                res[front[1]].append(front[0].val)
                if i % 2 == 0:
                    if front[0].left:
                        stack.append((front[0].left, front[1]+1))
                    if front[0].right:
                        stack.append((front[0].right, front[1]+1))
                else:
                    if front[0].right:
                        stack.append((front[0].right, front[1]+1))
                    if front[0].left:
                        stack.append((front[0].left, front[1]+1))
            else:
                for j in range(len(stack)-1, -1, -1):
                    que.put(stack[j])
                stack = []
                i += 1
        return res


if __name__ == '__main__':
    root = TreeNode(0)
    p1 =root.left = TreeNode(2)
    p2 = root.right = TreeNode(4)
    p3 = p1.left = TreeNode(1)
    p3.left = TreeNode(5)
    p3.right = TreeNode(1)
    p4 = p2.left = TreeNode(3)
    p5 = p2.right = TreeNode(-1)
    p4.right = TreeNode(6)
    p5.right = TreeNode(8)
    s = Solution()
    print(s.zigzagLevelOrder(root))




