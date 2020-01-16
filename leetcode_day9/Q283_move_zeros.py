# 给定一个数组 nums，编写一个函数将所有 0 移动到数组的末尾，同时保持非零元素的相对顺序。
#
# 示例:
#
# 输入: [0,1,0,3,12]
# 输出: [1,3,12,0,0]


class Solution:
    def moveZeroes(self, nums: list) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """

        # [0, k)的区间内表示全部为非零
        # [i, n-1]表示需要被遍历的部分
        k, i = 0, 0
        while i < len(nums):
            if nums[i]:
                if i != k:
                    nums[k], nums[i] = nums[i], 0
                    k, i = k + 1, i + 1

                else:
                    k, i = k + 1, i + 1
            else:
                i += 1