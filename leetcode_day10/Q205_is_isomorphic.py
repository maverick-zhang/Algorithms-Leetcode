class Solution:
    def isIsomorphic(self, s: str, t: str) -> bool:
        if len(s) != len(t):
            return False
        record1 = {}
        record2 = {}
        for i in range(len(s)):
            if s[i] not in record1 and t[i] not in record2:
                record1[s[i]] = t[i]
                record2[t[i]] = s[i]
            elif s[i] in record1 and t[i] in record2:
                if record1[s[i]] != t[i] or record2[t[i]] != s[i]:
                    return False
            else:
                return False
        return True