# 解题思路要寻找(i, j, k)这三元组，首先可以对数组进行一次遍历，确定每一个i(题目已经说明点都不相同)
# 对于每一个i,其他的点，记录点i到其他店的距离并保存在字典中，字典的key为该距离，value为存在的点数
# 最后遍历这个字典，取出相同距离的点数，可能组合数即为Cn2


class Solution:
    def numberOfBoomerangs(self, points: list) -> int:
        res = 0
        for point_i in points:
            record = {}
            for point_j in points:
                if point_j != point_i:
                    distance = (point_j[0] - point_i[0]) ** 2 + (point_j[1] - point_i[1]) ** 2
                    if record.get(distance):
                        record[distance] += 1
                    else:
                        record[distance] = 1
            for val in record.values():
                res += val * (val - 1)
        return res


if __name__ == '__main__':
    s = Solution()
    print(s.numberOfBoomerangs([[0, 0], [1, 0], [2, 0]]))