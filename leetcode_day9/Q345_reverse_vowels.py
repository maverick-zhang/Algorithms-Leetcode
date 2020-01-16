class Solution:
    def reverseVowels(self, s: str) -> str:
        i, j = 0, len(s)-1
        vowels = {"a", "o", "u", "i", "e"}
        s = list(s)
        while i < j:
            if s[i].lower() not in vowels:
                i += 1
                continue
            elif s[j].lower() not in vowels:
                j -= 1
                continue
            s[i], s[j] = s[j], s[i]
            i, j = i + 1, j - 1
        return "".join(s)