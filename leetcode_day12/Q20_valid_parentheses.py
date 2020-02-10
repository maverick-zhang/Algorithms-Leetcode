class Solution:
    def isValid(self, s: str) -> bool:
        left = {'(', '[', '{'}
        stack = []
        for ch in s:
            if ch in left:
                stack.append(ch)
            else:
                if not stack:
                    return False
                if ch == ')':
                    top = stack.pop()
                    if top != '(':
                        return False
                elif ch == ']':
                    top = stack.pop()
                    if top != '[':
                        return False
                else:
                    top = stack.pop()
                    if top != '{':
                        return False
        return not bool(stack)