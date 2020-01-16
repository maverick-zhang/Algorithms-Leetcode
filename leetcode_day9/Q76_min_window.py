# 给你一个字符串 S、一个字符串 T，请在字符串 S 里面找出：包含 T 所有字母的最小子串。
#
# 示例：
#
# 输入: S = "ADOBECODEBANC", T = "ABC"
# 输出: "BANC"

class Solution:
    def minWindow(self, s: str, t: str) -> str:
        char_num = [0]*256
        res = []
        chars = set()
        for ch in t:
            char_num[ord(ch)] += 1
            chars.add(ch)
        t_len = len(t)
        count = 0
        # [l, r]区间内的字符为t中字符的数量为count
        l, r = 0, -1
        while l < len(s):
            if (count < t_len and r + 1 < len(s)):
                if s[r+1] in chars:
                    char_num[ord(s[r+1])] -= 1
                    if char_num[ord(s[r+1])] >= 0:
                        count += 1
                r += 1
            else:
                if s[l] in chars:
                    char_num[ord(s[l])] += 1
                    if char_num[ord(s[l])] > 0:
                        count -= 1
                l += 1
            if count == t_len:
                if not res:
                    res.extend([l, r])
                else:
                    if r-l < res[1] - res[0]:
                        res[0] = l
                        res[1] = r
        if not res:
            return ""
        else:
            return s[res[0]:res[1]+1]


if __name__ == '__main__':
    s = Solution()
    s.minWindow("ADOBECODEBANC", "ABC")
