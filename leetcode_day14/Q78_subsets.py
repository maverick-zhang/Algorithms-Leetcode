class Solution:
    def __init__(self):
        self.res = []

    #寻找k个数字的组合，下标从index开始
    def combination(self, nums, k, index, res):
        if k == 0:
            self.res.append(list(res))
            return
        if k > len(nums):
            return

        for i in range(index, len(nums)-k + 1):
            res.append(nums[i])
            self.combination(nums, k-1, i + 1, res)
            res.pop()

    def subsets(self, nums: list) -> list:
        self.res.append([])
        for i in range(1, len(nums) + 1):
            self.combination(nums, i, 0, [])
        return self.res


if __name__ == '__main__':
    s = Solution()
    print(s.subsets([1, 2, 2]))