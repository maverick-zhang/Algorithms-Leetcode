# 解题思路：维持一个大小不超过k+1的窗口，如果在这个窗口内存在重复的元素，则返回true


class Solution:
    def containsNearbyDuplicate(self, nums: list, k: int) -> bool:
        if k < 1:
            return False
        record = set()
        for i in range(len(nums)):
            if nums[i] in record:
                return True
            if len(record) == k:
                record.remove(nums[i-k])
            record.add(nums[i])
        return False


if __name__ == '__main__':
    s = Solution()
    print(s.containsNearbyDuplicate([1,2,1], 0))

