# 找出所有相加之和为 n 的 k 个数的组合。组合中只允许含有 1 - 9 的正整数，并且每种组合中不存在重复的数字。
#
# 说明：
#
# 所有数字都是正整数。
# 解集不能包含重复的组合。


class Solution:
    def __init__(self):
        self.res = []

    def __combination(self, k, n, index, res):
        if k == 0:
            if n == 0:
                self.res.append(list(res))
            return

        for i in range(index, 10):
            if i > n:
                break
            res.append(i)
            self.__combination(k-1, n-i, i + 1, res)
            res.pop()

    def combinationSum3(self, k: int, n: int) -> list:
        if k <= 0 or n <= 0:
            return []
        res = []
        self.__combination(k, n, 1, res)
        return self.res

