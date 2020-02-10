# 根据逆波兰表示法，求表达式的值。
#
# 有效的运算符包括 +, -, *, / 。每个运算对象可以是整数，也可以是另一个逆波兰表达式。
#
# 说明：
#
# 整数除法只保留整数部分。
# 给定逆波兰表达式总是有效的。换句话说，表达式总会得出有效数值且不存在除数为 0 的情况。
# 示例 1：
#
# 输入: ["2", "1", "+", "3", "*"]
# 输出: 9
# 解释: ((2 + 1) * 3) = 9

# 输入: ["4", "13", "5", "/", "+"]
# 输出: 6
# 解释: (4 + (13 / 5)) = 6

class Solution:
    def operate(self, num1, num2, ch):
        if ch == '+':
            return num1 + num2
        elif ch == '-':
            return num1 - num2
        elif ch == '*':
            return num1 * num2
        else:
            return int(num1/num2)

    def evalRPN(self, tokens:list) -> int:
        operators = {'+', '-', '*', '/'}
        stack = []
        for ch in tokens:
            if ch in operators:
                num2 = stack.pop()
                num1 = stack.pop()
                stack.append(self.operate(num1, num2, ch))
            else:
                stack.append(int(ch))
        return stack[0]
# ["17","+","5","+"]

if __name__ == '__main__':
    s = Solution()
    print(s.evalRPN(["10", "6", "9", "3", "+", "-11", "*", "/", "*", "17", "+", "5", "+"]))

