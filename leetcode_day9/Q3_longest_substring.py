class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        # [l, r]为子串区间，左闭右闭
        ascii_chars = [0] * 256
        l, r = 0, -1
        res = 0
        while l < len(s):
            if (r+1<len(s)) and ascii_chars[ord(s[r+1])] == 0:
                r, ascii_chars[ord(s[r])] = r+1, 1
            else:
                ascii_chars[ord(s[l])], l = 0, l+1
            res = max(res, r-l+1)

        return res