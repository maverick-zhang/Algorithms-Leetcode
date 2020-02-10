# 输入："/a/../../b/../c//.//"
# 输出："/c"

class Solution:
    def simplifyPath(self, path: str) -> str:
        stack = []
        dot = False
        for i in range(len(path)):
            if path[i] == '/':
                if not stack or stack[-1] != '/':
                    stack.append(path[i])
                dot = False
            elif path[i] == '.':
                if stack[-1] == '.':
                    stack.append('.')
                    continue
                if not dot:
                    dot = True
                elif i == len(path) - 1 or path[i+1] == '/':
                    if stack[-1] == '/':
                        stack.pop()
                    while stack and  stack.pop() != '/':
                        continue
                    if not stack:
                        stack.append('/')
                    dot = False
                else:
                    stack.append('.')
                    stack.append('.')
                    dot = False
            else:
                if dot:
                    stack.append('.')
                    dot = False
                stack.append(path[i])
        if len(stack) > 1 and stack[-1] == '/':
            stack.pop()
        return "".join(stack)
