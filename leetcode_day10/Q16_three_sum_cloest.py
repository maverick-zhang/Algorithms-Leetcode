# 对撞法的数学证明
# l, r的取值范围为[i+1, n-1]，初始l=i+1, r = n-1
# 对于当前遍历的nums[i],如果target-(nums[l]+nums[r]+nums[i])>0，此时指针r向左移动，即忽略了(k,r)数值对(k的取值范围为[l+1, r-1])
# nums[i] + nums[k] + nums[r] > nums[i] + nums[l] + nums[r](k > l)因此这些取值对只会更大，所以可以进行丢弃。同理可证另一种情况


class Solution:
    def threeSumClosest(self, nums:list,  target ) -> int:

        nums.sort()
        res = None
        i = 0
        while i < len(nums):
            # [i + 1, n-1]进行对撞
            # while i - 1 >= 0 and nums[i] == nums[i-1]:
            # i += 1

            l, r = i + 1, len(nums)-1
            while l < r:
                three_sum = nums[i] + nums[l] + nums[r]
                if res is None or abs(target-three_sum) < abs(target-res):
                    res = three_sum
                if target-three_sum == 0:
                    return target
                elif target - three_sum > 0:
                    l += 1
                else:
                    r -= 1
            i += 1
        return res



if __name__ == '__main__':
    s = Solution()
    print(s.threeSumClosest([0,2,1,-3], 1))


