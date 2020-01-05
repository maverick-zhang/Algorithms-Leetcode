//
// Created by maverick on 2020/1/1.
//

#ifndef ALGORITHMS_Q347_TOP_K_FREQUENT_H
#define ALGORITHMS_Q347_TOP_K_FREQUENT_H

#include <vector>
#include <queue>
#include <unordered_map>


using namespace std;

//给定一个非空的整数数组，返回其中出现频率前 k 高的元素。
//
//示例 1:
//
//输入: nums = [1,1,1,2,2,3], k = 2
//输出: [1,2]

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {

        //<数， 频率>
        unordered_map<int, int> freq;

        for(int num: nums)
            freq[num] ++;

        //<频率， 数>
        //优先队列<存储数据类型， 内部实现的方式， 排序方法>
        priority_queue<pair<int, int>, vector<pair<int, int >>, greater<pair<int, int >>> pri_que;

        for(auto iter = freq.begin(); iter != freq.end(); iter ++)
        {
            if (pri_que.size() == k)
            {
                if (iter->second > pri_que.top().first)
                {
                    pri_que.pop();
                    pri_que.push(make_pair(iter->second, iter->first));
                }
            }
            else
                pri_que.push(make_pair(iter->second, iter->first));
        }

        vector<int> res;

        while (!pri_que.empty())
        {
            res.push_back(pri_que.top().second);
            pri_que.pop();
        }

        return res;

    }
};

#endif //ALGORITHMS_Q347_TOP_K_FREQUENT_H
