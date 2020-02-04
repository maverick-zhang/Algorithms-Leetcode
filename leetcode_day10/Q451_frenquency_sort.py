from operator import itemgetter

class Solution:
    def frequencySort(self, s: str) -> str:
        record = {}
        for ch in s:
            if ch not in record:
                record[ch] = 1
            else:
                record[ch] += 1
        list2 = sorted(record.items(), key=itemgetter(1), reverse=True)
        res = ""
        for ch, num in list2:
            res += ch * num
        return res


if __name__ == '__main__':
    s = Solution()
    print(s.frequencySort("Abaa"))