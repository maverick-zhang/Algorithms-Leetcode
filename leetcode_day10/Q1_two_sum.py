class Solution:
    def twoSum(self, nums: list, target: int):
        record = {}
        for i in range(len(nums)):
            if record.get(target-nums[i]) is not None:
                return [record[target-nums[i]], i]
            else:
                record[nums[i]] = i


if __name__ == '__main__':
    s = Solution()
    s.twoSum([2,7,11, 12], 9)
