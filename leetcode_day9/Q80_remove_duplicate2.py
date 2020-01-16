class Solution:
    def removeDuplicates(self, nums: list[int]) -> int:
        n = len(nums)
        if n < 3:
            return n
        k, i = 2, 2
        while i < n:
            if nums[i] == nums[k-1] == nums[k-2]:
                i += 1
            else:
                if i != k:
                    nums[k] = nums[i]
                i, k = i+1, k + 1
        return k