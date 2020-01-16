class Solution:
    def maxArea(self, height: list) -> int:
        i, j = 0, len(height)-1
        max_area = 0
        while i < j:
            max_area = max(max_area, (j-i)*min(height[i], height[j]))
            if height[j] < height[i]:
                j -= 1
            else:
                i += 1
        return max_area