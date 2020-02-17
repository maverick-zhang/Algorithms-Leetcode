class Solution:
    def __init__(self):
        self.res = []
        self.used = None

    def __permute(self, nums, index, res):
        if index == len(nums):
            self.res.append(res)
            return

        for i in range(len(nums)):
            if not self.used[i]:
                res.append(nums[i])
                self.used[i] = True
                self.__permute(nums, index+1, list(res))
                self.used[i] = False
                res.pop()

    def permute(self, nums: list) -> list:
        if not nums:
            return []
        self.used = [False] * len(nums)
        self.__permute(nums, 0, [])
        return self.res
