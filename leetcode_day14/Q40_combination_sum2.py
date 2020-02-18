# 给定一个数组 candidates 和一个目标数 target ，找出 candidates 中所有可以使数字和为 target 的组合。
#
# candidates 中的每个数字在每个组合中只能使用一次。
#
# 说明：
#
# 所有数字（包括目标数）都是正整数。
# 解集不能包含重复的组合。 

# candidates 中的每个数字在每个组合中只能使用一次。
#
# 说明：
#
# 所有数字（包括目标数）都是正整数。
# 解集不能包含重复的组合。 



class Solution:
    def __init__(self):
        self.res = []
        self.record = {}

    def __combination(self, candidates, target, index, res):
        if target == 0:
            self.res.append(list(res))
            return

        if target < 0 or index >= len(candidates):
            return

        i = index
        while i < len(candidates) and candidates[i] <= target:
            num_count = self.record[candidates[i]]
            target_bk = target
            while num_count > 0:
                res.append(candidates[i])
                self.__combination(candidates, target-candidates[i], i + 1, res)
                target = target - candidates[i]
                num_count -= 1
            num_count = self.record[candidates[i]]
            while num_count > 0:
                res.pop()
                num_count -= 1
            target = target_bk
            i += 1


    def combinationSum2(self, candidates: list, target: int) -> list:
        if not candidates or target <= 0:
            return []
        for num in candidates:
            if self.record.get(num):
                self.record[num] += 1
            else:
                self.record[num] = 1

        candidates = list(self.record.keys())
        candidates.sort()
        res = []
        self.__combination(candidates, target, 0, res)
        return self.res


if __name__ == '__main__':
    s = Solution()
    print(s.combinationSum2([10, 1, 2, 7, 6, 1, 5], 8))
