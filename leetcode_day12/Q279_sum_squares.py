from queue import Queue
from array import array
# 使用图的广度优先遍历
# 图上的每一个节点为数字num,初始节点为n,遍历i(1, n)把每一个n-i^2放入图中，这样既可以找到最短的路径
class Solution:
    def numSquares(self, n: int) -> int:
        que = Queue()
        mark = array('b', [0]*n)
        que.put((n, 0))
        while not que.empty():
            front = que.get()
            for i in range(1, front[0]+1):
                a = front[0] - i*i
                if a == 0:
                    return front[1] + 1
                if a < 0:
                    break
                if not mark[a]:
                    que.put((a, front[1]+1))
                    mark[a] = 1
