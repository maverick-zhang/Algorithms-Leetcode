//
// Created by maverick on 2019/12/25.
//

#ifndef ALGORITHMS_Q49_GROUP_ANAGRAMS_H
#define ALGORITHMS_Q49_GROUP_ANAGRAMS_H

#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>

using namespace std;

//给定一个字符串数组，将字母异位词组合在一起。字母异位词指字母相同，但排列不同的字符串。
//
//示例:
//
//输入: ["eat", "tea", "tan", "ate", "nat", "bat"],
//输出:
//[
//["ate","eat","tea"],
//["nat","tan"],
//["bat"]
//]

class Solution {
private:
    void has_recorded(const string & s, unordered_map<string, vector<string>> & record)
    {
        vector<char> vt_s;
        for (char ch: s)
            vt_s.push_back(ch);
        sort(vt_s.begin(), vt_s.end());
        string to_record(vt_s.begin(), vt_s.end());
        if (record.find(to_record) == record.end())
        {
            vector<string> temp{s};
            record.insert(make_pair(to_record,temp));
        }
        else
            record[to_record].push_back(s);
    }
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {

        //使用一个字典,key为string,value为返回结果res二维数组的第一位索引
        //字典中的key是更改过的str，把str的字母重新排序后放入字典
        //优化：直接把字典的value作为vector<string>，最后把vector合并到res中.

        vector<vector<string>> res;

        unordered_map<string, vector<string>> record;

        int size_of_res = -1;

        for (string & s: strs)
        {
            has_recorded(s, record);
        }

        for (auto & p: record) {
            res.push_back(p.second);
        }
        return res;
    }
};



#endif //ALGORITHMS_Q49_GROUP_ANAGRAMS_H
