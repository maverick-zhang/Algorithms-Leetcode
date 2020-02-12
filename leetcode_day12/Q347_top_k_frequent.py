import heapq


#算法思路，维护一个只能容纳你n-k个元素的优先队列，把每个元素进行统计，计算其出现的频次
# 把统计出来的(频率， 元素)组成一对放到优先队列中，如果优先队列尚未满则直接放入，
# 如果此时优先队列已经满了，则取出队列顶部的元素
class Solution:
    def topKFrequent(self, nums: list, k: int) -> list:
        if not nums:
            return []
        record = {}
        for num in nums:
            if record.get(num):
                record[num] += 1
            else:
                record[num] = 1
        top_k = heapq.nlargest(k, ((val, key) for key, val in record.items()))
        return [elm[1] for elm in top_k]


if __name__ == '__main__':
    s = Solution()
    print(s.topKFrequent( [1,1,1,2,2,3], 2))
