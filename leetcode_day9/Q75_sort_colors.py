class Solution:
    def sortColors(self, nums: list) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        # 使用三路快排的思路进行排序
        zero = -1   # [0, zero]区间内的所有数字都为0
        two = len(nums)  # [two, len(nums)-1]范围内的所有数字都为2
        i = 0   # [zero+1, i-1]范围内的所有数字都为1

        while i < two:
            if nums[i] == 0:
                nums[i], nums[zero+1] = nums[zero+1], nums[i]
                i += 1
                zero += 1
            elif nums[i] == 1:
                i += 1
            else:
                nums[i], nums[two-1] = nums[two-1], nums[i]
                two -= 1
