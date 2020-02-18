# 给定一个无重复元素的数组 candidates 和一个目标数 target ，找出 candidates 中所有可以使数字和为 target 的组合。
#
# candidates 中的数字可以无限制重复被选取。
#
# 说明：
#
# 所有数字（包括 target）都是正整数。
# 解集不能包含重复的组合。


class Solution:
    def __init__(self):
        self.res = []

    def __combination(self, candidates, index, target, res):
        if target == 0:
            self.res.append(list(res))
            return
        if target < 0 or index >= len(candidates):
            return

        for i in range(index, len(candidates)):
            if candidates[i] > target:
                break
            res.append(candidates[i])
            self.__combination(candidates, i, target-candidates[i], res)
            res.pop()

    def combinationSum(self, candidates: list, target: int) -> list:
        unique_candidates = set(candidates)
        candidates = list(unique_candidates)
        candidates.sort()
        res = []
        self.__combination(candidates, 0, target, res)
        return self.res


if __name__ == '__main__':
    s = Solution()
    print(s.combinationSum([2, 3, 6, 7], 7))

