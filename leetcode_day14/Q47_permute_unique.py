# 输出:
# [
#     [1,1,2],
#     [1,2,1],
#     [2,1,1]
# ]

class Solution:
    def __init__(self):
        self.record = None
        self.res = []

    def __permute(self, nums, index, res):
        if index == len(nums):
            self.res.append(res)
            return

        for key in self.record.keys():
            if self.record[key] >= 1:
                res.append(key)
                self.record[key] -= 1
                self.__permute(nums, index+1, list(res))
                res.pop()
                self.record[key] += 1

    def permuteUnique(self, nums: list) -> list:
        if not nums:
            return []
        self.record = {}
        for num in nums:
            if self.record.get(num):
                self.record[num] += 1
            else:
                self.record[num] = 1
        self.__permute(nums, 0, [])
        return self.res


if __name__ == '__main__':
    s = Solution()
    print(s.permuteUnique([1,1,2]))
