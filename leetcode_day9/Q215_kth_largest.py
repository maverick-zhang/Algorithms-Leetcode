import random

class Solution:

    def __partition(self, nums, l, r, k):

        if l == r:
            return nums[l]

        rand_num  = random.randint(l ,r)
        nums[l], nums[rand_num] = nums[rand_num], nums[l]
        val = nums[l]
        lt, gt, i = l, r + 1, l + 1   # [l, lt]为小于val的部分, (lt, i)为等于val的部分，[gt, r]为大于val的部分

        while i < gt:
            if nums[i] == val:
                i += 1
            elif nums[i] > val:
                nums[i], nums[gt-1] = nums[gt-1], nums[i]
                gt -= 1
            else:
                nums[i], nums[lt+1] = nums[lt+1], nums[i]
                i, lt = i + 1, lt + 1

        nums[l], nums[lt] = nums[lt], nums[l]
        if gt+1 <= k:
            return self.__partition(nums, gt, r, k)
        elif lt >= k:
            return self.__partition(nums, l, lt-1, k)
        else:
            return nums[lt]

    def findKthLargest(self, nums: list, k: int) -> int:

        l, r = 0, len(nums)-1
        # 第k大转为从小到大第k个
        k = len(nums) - k + 1
        return self.__partition(nums, l, r, k)


