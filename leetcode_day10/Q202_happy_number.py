class Solution:

    def __init__(self):
        self.record = set()

    def isHappy(self, n: int) -> bool:
        if n == 1:
            return True
        if n in self.record:
            return False
        self.record.add(n)
        res = 0
        while n > 0:
            res += (n%10)**2
            n = n // 10
        return self.isHappy(res)




if __name__ == '__main__':
    s = Solution()
    s.isHappy(19)