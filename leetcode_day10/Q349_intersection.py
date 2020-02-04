# 给定两个数组，求出其交集

class Solution:
    def intersection(self, nums1: list, nums2: list):
        set1 = set(nums1)
        set2 = set(nums2)
        return list(set1.intersection(set2))