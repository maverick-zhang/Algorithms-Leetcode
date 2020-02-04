# 输入: ["eat", "tea", "tan", "ate", "nat", "bat"],
# 输出:
# [
#     ["ate","eat","tea"],
#     ["nat","tan"],
#     ["bat"]
# ]


class Solution:
    def groupAnagrams(self, strs: list):

        res = []
        record = {}
        for word in strs:
            word_l = list(word)
            word_l.sort()
            new_word = "".join(word_l)
            if record.get(new_word):
                record[new_word].append(word)
            else:
                record.update({new_word:[word]})
        for value in record.values():
            res.append(value)
        print(res)
        return res


if __name__ == '__main__':
    s = Solution()
    s.groupAnagrams(["eat", "tea", "tan", "ate", "nat", "bat"])

