class Solution:
    def findAnagrams(self, s: str, p: str) -> list:
        chars_num = {}
        res = []
        for ch in p:
            if ch in chars_num:
                chars_num[ch] += 1
            else:
                chars_num[ch] = 1
        l = 0
        while l < len(s):
            while l < len(s) and s[l] not in chars_num:
                l += 1
            if l >= len(s):
                break
            # [l, r]为子串的区间
            r = l
            copy_dict = dict(chars_num)
            copy_dict[s[l]] -= 1
            while r-l + 1 < len(p):
                if r + 1 < len(s) and copy_dict.get(s[r+1]):
                    copy_dict[s[r+1]] -= 1
                    r += 1
                else:
                    l += 1
                    break

            if r-l + 1 == len(p):
                res.append(l)
                l += 1
        return res


if __name__ == '__main__':
    s = Solution()
    s.findAnagrams("cbaebabacd", "abc")
