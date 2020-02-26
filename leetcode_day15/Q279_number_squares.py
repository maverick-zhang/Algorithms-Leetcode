class Solution:
    def numSquares(self, n: int) -> int:
        record = [None] * (n+1)
        for i in range(n+1):
            if i*i >n: break
            record[i*i] = 1

        for i in range(2, n+1):
            if record[i]:
                continue
            min_res = None
            for j in range(1, i):
                if j*j >i:
                    break
                if not min_res:
                    min_res = record[i-j*j] + 1
                else:
                    min_res = min(min_res, record[i-j*j] + 1)
            record[i] = min_res
        return record[n]

if __name__ == '__main__':
    s = Solution()
    print(s.numSquares(1))