# 使用双指针对撞首先需要对数组进行排序
# 思路，使用双指针对撞的方法寻找target
# 首先对nums进行一次外层循环，对于每一个遍历到的nums[i]，在[i+1, n-1]的范围内寻找三元组，其和为target-nums[i]


class Solution:
    def fourSum(self, nums: list, target: int):
        res = []
        nums.sort()
        i = 0
        while i < len(nums):
            while 0 <= i-1 <= len(nums)-2 and nums[i] == nums[i-1]:
                i += 1
            if i >= len(nums):
                break
            new_target = target - nums[i]
            j = i + 1
            while j < len(nums):
                while j > i + 1 and j < len(nums) and nums[j] == nums[j-1]:
                    j += 1
                l, r = j + 1, len(nums) - 1
                while l < r:
                    if nums[j] + nums[l] + nums[r] == new_target:
                        while l < r and nums[l] == nums[l+1]:
                            l += 1
                        while l < r and nums[r] == nums[r-1]:
                            r -= 1
                        res.append([nums[i], nums[j], nums[l], nums[r]])
                        l += 1
                        r -= 1
                    elif nums[j] + nums[l] + nums[r] < new_target:
                        l += 1
                    else:
                        r -= 1
                j += 1
            i += 1
        # print(res)
        return res

if __name__ == '__main__':
    s = Solution()
    s.fourSum([-1,0,1,2,-1,-4], -1)


