class Solution:
    def climbStairs(self, n: int) -> int:
        if n == 1:
            return 1
        if n == 2:
            return 2
        record = [0] * (n+1)
        record[1], record[2] = 1, 2
        for i in range(3, n+1):
            record[i] = record[i-1] + record[i-2]
        return record[n]

