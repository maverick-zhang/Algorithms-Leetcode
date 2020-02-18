class Solution:
    def __init__(self):
        self.res = []

    def __combination(self, n, k, index, res):
        if len(res) == k:
            self.res.append(list(res))
            return

        # [index, n]之间需要保证稀少有k - len(res)个元素  即
        for i in range(index, n - (k - len(res)) + 2):
            res.append(i)
            self.__combination(n, k, i + 1, res)
            res.pop()

    def combine(self, n: int, k: int) -> list:
        if n<=0 or k <= 0 or k > n:
            return []
        res= []
        self.__combination(n, k, 1, res)
        return self.res


if __name__ == '__main__':
    s = Solution()
    print(s.combine(4, 2))