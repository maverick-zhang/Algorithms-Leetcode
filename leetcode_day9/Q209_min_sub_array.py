class Solution:
    def minSubArrayLen(self, s: int, nums: list) -> int:
        # [l, r]为子序列
        l, r = 0, -1
        res = len(nums) + 1
        sum = 0
        while l < len(nums):
            if sum < s and r+1 < len(nums):
                sum += nums[r+1]
                r += 1
            else:
                sum -= nums[l]
                l += 1
            if sum >= s:
                res = min(res, r-l+1)

        if res == len(nums) + 1:
            return 0
        return res