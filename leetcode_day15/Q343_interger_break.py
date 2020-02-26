class Solution:
    def integerBreak(self, n: int) -> int:
        if n == 2:
            return 1
        if n == 3:
            return 2
        record = [0] * (n+1)
        record[1] = record[2] = 1
        for num in range(2, n+1):
            max_res = num
            for j in range(1, n):
                max_res = max(max_res, j * record[num-j])
            record[num] = max_res
        return record[n]


if __name__ == '__main__':
    s = Solution()
    print(s.integerBreak(10))