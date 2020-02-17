# 输入: "aab"
# 输出:
# [
#     ["aa","b"],
#     ["a","a","b"]
# ]

class Solution:
    def __init__(self):
        self.res = []

    def is_palindrome(self, string):
        i, j = 0, len(string) - 1
        while i < j:
            if string[i] == string[j]:
                i, j = i + 1, j - 1
            else:
                return False
        return True

    def __partition(self, s, index, res):
        if index == len(s):
            self.res.append(res)
            return

        remain_num = len(s) - index
        for i in range(1, remain_num+1):
            tem = s[index:index+i]
            if self.is_palindrome(tem):
                res.append(tem)
                self.__partition(s, index+i, list(res))
                res.pop()


    def partition(self, s: str) -> list:
        if not s:
            return []
        res = []
        self.__partition(s, 0, res)
        return self.res


if __name__ == '__main__':
    s = Solution()
    print(s.partition("aab"))