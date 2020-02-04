class Solution:
    def intersect(self, nums1: list, nums2: list) ->list:
        record = {}
        for num in nums1:
            if num not in record:
                record[num] = 1
            else:
                record[num] += 1
        res = []
        for num in nums2:
            if num in record and record[num] > 0:
                res.append(num)
                record[num] -= 1
        return res
