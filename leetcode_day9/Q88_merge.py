class Solution:
    def merge(self, nums1: list, m: int, nums2: list, n: int) -> None:
        """
        Do not return anything, modify nums1 in-place instead.
        """
        if n == 0:
            return
        nums1_copy = list(nums1)
        i, j, k = 0, 0, 0
        while i < m or j < n:
            if i == m or (j < n and nums1_copy[i] > nums2[j]):
                nums1[k] = nums2[j]
                j, k = j + 1, k + 1
            else:
                nums1[k] = nums1_copy[i]
                i, k = i + 1, k + 1

