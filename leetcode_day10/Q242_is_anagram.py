# 给定两个字符串 s 和 t ，编写一个函数来判断 t 是否是 s 的字母异位词。
#
# 示例 1:
#
# 输入: s = "anagram", t = "nagaram"
# 输出: true

class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        record = {}
        for ch in s:
            if ch in record:
                record[ch] += 1
            else:
                record[ch] = 1
        for ch in t:
            if ch in record:
                record[ch] -= 1
            else:
                return False
        for key, value in record.items():
            if value != 0:
                return False
        return True