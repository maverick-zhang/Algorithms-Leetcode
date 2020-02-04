class Solution:
    def threeSum(self, nums: list):

        res = []
        # if len(nums) < 3:
        #     return res
        record = {}

        nums.sort()
        dup = [False] * len(nums)
        i = 0
        while i < len(nums):
            if i-1 >= 0 and nums[i] == nums[i-1]:
                dup[i] = True
                if not dup[i-1]:
                    if record.get(-nums[i] * 2) is not None:
                        record[-nums[i] * 2].append((i-1, i))
                    else:
                        record[-nums[i] * 2] = [(i-1, i)]
                    for j in range(0, i-1):
                        if nums[j] == -nums[i] * 2:
                            res.append([nums[j], nums[i], nums[i]])
                            break
                i += 1
                continue

            if record.get(nums[i]):
                for pair in record.get(nums[i]):
                    res.append([nums[pair[0]], nums[pair[1]], nums[i]])
            else:
                for j in range(0, i):
                    while j - 1 >= 0 and nums[j-1] == nums[j]:
                        j += 1
                    if record.get(-nums[i]-nums[j]) is not None:
                        record[-nums[i]-nums[j]].append((i, j))
                    else:
                        record[-nums[i]-nums[j]] = [(i, j)]
            i += 1

        return res


if __name__ == '__main__':
    s = Solution()
    s.threeSum([0, 0, 0])