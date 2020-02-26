# [
#     [2],
#     [3,4],
#     [6,5,7],
#     [4,1,8,3]
# ]

# 所谓的相邻节点，假设当前层的索引为[i][j],那么其相邻节点为[i+1][j]和[i+1][j+1]
# 问题转化为从顶层开始选择哪一个相邻节点的问题使得和最小
class Solution:

    def __init__(self):
        self.record = []

    def find_path(self, triangle, i, j):
        if i == len(triangle) - 1:
            return triangle[i][j]

        if self.record[i][j] is not None:
            return self.record[i][j]
        else:
            res = min(self.find_path(triangle, i+1, j), self.find_path(triangle, i+1, j+1)) + triangle[i][j]
            self.record[i][j] = res
            return res

    def minimumTotal(self, triangle: list) -> int:
        for i in range(len(triangle)):
            self.record.append([None] * len(triangle))
        return self.find_path(triangle, 0, 0)


def minimum_total(triangle):
    record = []
    for i in range(len(triangle)):
        record.append([0] * len(triangle))
    for j in range(len(triangle[-1])):
        record[-1][j] = triangle[-1][j]
    for i in range(len(triangle)-2, -1, -1):
        for j in range(len(triangle[i])):
            record[i][j] += min(triangle[i+1][j], triangle[i+1][j+1])
    return record[0][0]
