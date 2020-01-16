class Solution:
    def removeDuplicates(self, nums: list) -> int:

        n = len(nums)
        # [0, k)表示不包含重复元素的区间， [i, n-1]表示尚需要遍历的区间
        i, k = 0, 0

        while i < n:
            if i == 0:
                i, k = i + 1, k + 1
                continue
            if nums[i] == nums[i-1]:
                i += 1
            else:
                if i != k:
                    nums[k] = nums[i]
                i, k = i + 1, k + 1
        return k