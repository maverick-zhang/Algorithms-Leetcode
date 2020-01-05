//
// Created by maverick on 2020/1/1.
//

#ifndef ALGORITHMS_Q127_LADDER_LENGTH_H
#define ALGORITHMS_Q127_LADDER_LENGTH_H

#include <string>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <queue>
using namespace std;

//给定两个单词（beginWord 和 endWord）和一个字典，找到从 beginWord 到 endWord 的最短转换序列的长度。转换需遵循如下规则：
//
//每次转换只能改变一个字母。
//转换过程中的中间单词必须是字典中的单词。
//说明:
//
//如果不存在这样的转换序列，返回 0。
//所有单词具有相同的长度。
//所有单词只由小写字母组成。
//字典中不存在重复的单词。
//你可以假设 beginWord 和 endWord 是非空的，且二者不相同。




class Solution {
    bool is_linked(const string & s1, const string & s2)
    {
        if (s1.size() != s2.size())
            return false;

        bool found = false;
        for (int i = 0; i < s1.size(); ++i) {
            if (s1[i] != s2[i])
            {
                if (found)
                    return false;
                else
                    found = true;
            }
        }

        return found;
    }
public:

    //寻找单词的过程可以理解为图的最短路径问题
    //每一个单词都是图中的一个节点，是否可以进行相互转换组成了图的邻边
    //算法思路：从初始单词作为首节点，列表中遍历节点并找到可以进行转换的单词放到图中,逐渐遍历直到下一个单词是endword


    //当节点不断增多，而题目只需要一个解，这时可以采用双向BFS遍历，可以减少遍历的次数
    //从begin_word->end_word, end_word->begin_word，两个遍历碰头时即表示找到结果
    //在map_node中记录节点被遍历的次数，当遍历两次时即表示遍历碰头
    //问题在于如何记录两端的步长...因此需要额外使用两个字典，记录begin_word到该节点的距离以及end_word到该节点的距离


    //倒数第二个测试用例不通过。。。。。fuck

    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {

        bool in_list = false;
        for (string & str: wordList)
        {
            if (endWord == str)
                in_list = true;
        }
        if (!in_list)
            return 0;

        unordered_map<string, int> map_node;
        unordered_map<string, int> dist[2];
        queue<pair<string, int>> que[2];
        que[0].push(make_pair(beginWord, 1));
        que[1].push(make_pair(endWord, 1));

        string temp;
        int layer = 1;
        int direction = 0;
        int reverse = 1;
        int step = 1;
        while (!que[0].empty())
        {
            direction = (que[0].size() <= que[1].size())?0:1;
            reverse = (direction)?0:1;
            layer = que[direction].front().second;
            temp = que[direction].front().first;
            que[direction].pop();
            for (string & word: wordList)
            {

                if (dist[direction].find(word) == dist[direction].end() and is_linked(word, temp))
                {
                    if (direction and word == beginWord)
                        return layer + 1;
                    else if (!direction and word == endWord)
                        return layer + 1;
                    que[direction].push(make_pair(word, layer+1));
                    dist[direction].insert(make_pair(word, layer + 1));
                    map_node[word] ++;
                    if (map_node[word] == 2)
                        return dist[reverse][word] + layer;
                }
            }
            step ++;
        }

        return 0;
    }
};

// Time 68ms, 13.4MB
class Solution2 {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {

        unordered_map<string,int> freqs;

        for(const auto &word:wordList)
            freqs[word]=0;

        if(freqs.count(endWord)==0)
            return 0;

        queue<string> q1({beginWord}), q2({endWord});
        int step=1;

        for(freqs[beginWord]=1,freqs[endWord]=2; q1.size() && q2.size(); ++step){

            bool first=q1.size()<q2.size();

            queue<string> &q=first?q1:q2;
            int flag=first?1:2;
            for(int size=q.size(); size--; q.pop()){
                string &word=q.front();
                if(freqs[word]==3) return step;
                for(int i=0; i<word.length(); ++i){
                    for(char ch='a'; ch<='z'; ++ch){
                        string s=word;
                        if(s[i]==ch) continue;
                        s[i]=ch;
                        if(freqs.count(s)==0 || freqs[s]&flag) continue;
                        freqs[s]|=flag;
                        q.push(s);
                    }
                }
            }
        }
        return 0;
    }
};



#endif //ALGORITHMS_Q127_LADDER_LENGTH_H
