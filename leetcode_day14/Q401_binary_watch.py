# 转化为组合问题，即在10个灯中取n个；亮着的灯，然后再计算出时间
# 规定1-4为小时灯，5-10为分钟灯

class Solution:
    def __init__(self):
        self.res = []

    def interpret(self, lights):
        hour, minutes = 0, 0
        for num in lights:
            if num <= 4:
                hour += 2 ** (num - 1)
            else:
                minutes += 2 ** (num - 5)
        if hour > 11 or minutes > 59:
            return None
        return str(hour) + ":" + str(minutes).zfill(2)

    def combination(self, num, index, res):
        if num == 0:
            t = self.interpret(res)
            if t:
                self.res.append(t)
            return

        for i in range(index, 11-num+1):
            res.append(i)
            self.combination(num-1, i+1, res)
            res.pop()

    def readBinaryWatch(self, num: int) -> list:
        if num == 0:
            return ["0:00"]
        self.combination(num, 1, [])
        return self.res


if __name__ == '__main__':
    s = Solution()
    print(s.readBinaryWatch(1))