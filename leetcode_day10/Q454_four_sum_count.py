# 解题思路，首先对A和B中的数组进行遍历，求出所有可能和，然后保存到字典中，key = num1 + num2, value为出现的频次
# 然后再遍历C和D数组，求出所有的可能和，查找字典中是否存在相反数
class Solution:
    def fourSumCount(self, A: list, B: list, C: list, D: list):
        record = {}
        res = 0
        for num1 in A:
            for num2 in B:
                if record.get(num1+num2):
                    record[num1+num2] += 1
                else:
                    record.update({num1+num2: 1})
        for num3 in C:
            for num4 in D:
                if record.get(-num3-num4):
                    res += record[-num3-num4]
        return res