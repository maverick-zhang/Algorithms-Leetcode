class Solution:
    def __init__(self):
        self.map = {2:"abc", 3:"def", 4:"ghi", 5:"jkl", 6:"mno", 7:"pqrs", 8:"tuv", 9:"wxyz"}
        self.record = []

    def combination(self, digits, index, string):
        if index == len(digits):
            self.record.append(string)
            return

        letters = self.map[int(digits[index])]
        for letter in letters:
            self.combination(digits, index+1, string+letter)

    def letterCombinations(self, digits: str) -> list:
        if not digits:
            return []
        self.combination(digits, 0, "")
        return self.record
