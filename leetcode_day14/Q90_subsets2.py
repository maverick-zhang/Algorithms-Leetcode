class Solution:
    def __init__(self):
        self.res = []
        self.record = {}

    def combination(self, nums, k, index, res):
        if k == 0:
            self.res.append(list(res))
            return
        i = index
        while i < len(nums):
            num_count = self.record[nums[i]]
            k_bak = k
            while num_count > 0:
                res.append(nums[i])
                self.combination(nums, k-1, i+1, res)
                k -= 1
                num_count -= 1
            num_count = self.record[nums[i]]
            while num_count > 0:
                res.pop()
                num_count -= 1
            k = k_bak
            i += 1

    def subsetsWithDup(self, nums: list) -> list:
        if not nums:
            return []
        len_num = len(nums)
        for num in nums:
            if self.record.get(num):
                self.record[num] += 1
            else:
                self.record[num] = 1
        nums = list(self.record.keys())
        self.res.append([])
        for i in range(1, len_num+1):
            self.combination(nums, i, 0, [])
        return self.res

if __name__ == '__main__':
    s = Solution()
    print(s.subsetsWithDup([1, 2, 2]))