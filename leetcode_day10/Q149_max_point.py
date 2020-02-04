# 遍历所有点组成二元组，每一个二元组组成一条直线
# 把相同的直线归并在一起
# 相同直线的判断:直线采用y=ax+b的模式或x=b(此时a为inf)
# 复杂度O(n^2)

from fractions import Fraction

class Solution:
    def maxPoints(self, points: list) -> int:
        if len(points) <= 2:
            return len(points)
        points.sort()
        line_points = {}
        max_points = 2
        i = 0
        while i < len(points):
            same_point = 1
            while i + 1 < len(points) and points[i] == points[i+1]:
                i += 1
                same_point += 1
            prev_line = None
            for j in range(0, i):
                if points[j] == points[i]:
                    same_point -= 1
                if points[i][0] != points[j][0]:
                    a = Fraction(points[i][1]-points[j][1], points[i][0]-points[j][0])
                    b = Fraction(points[i][1], 1) - a * points[i][0]
                    line = (a, b)
                else:
                    b = Fraction(points[i][0], 1)
                    line = b
                if prev_line and prev_line == line:
                    continue
                else:
                    prev_line = line
                if line_points.get(line):
                    line_points[line] += same_point
                else:
                    line_points.update({line:same_point + 1})
                if line_points[line] > max_points:
                    max_points = line_points[line]
            i += 1
        return max_points

if __name__ == '__main__':
    s = Solution()
    a = s.maxPoints([[0,0],[1,1],[0,0]])
    print(a)