class Solution:
    def removeElement(self, nums: list, val: int) -> int:
        n = len(nums)
        if n == 0:
            return 0
        k, i = 0, 0
        # [0, k)的区间内都是不包含val的
        # [i, n-1]为需要被遍历的部分

        while i < n:
            if nums[i] != val:
                if i != k:
                    nums[i], nums[k] = nums[k], nums[i]
                    i, k = i + 1, k +1
                else:
                    i, k = i + 1, k+ 1
            else:
                i += 1

        return k
