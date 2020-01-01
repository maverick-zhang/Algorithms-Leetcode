//
// Created by maverick on 2019/12/31.
//

#ifndef ALGORITHMS_Q341_NESTED_LIST_H
#define ALGORITHMS_Q341_NESTED_LIST_H

#include <vector>
#include <queue>
#include <stack>

using std::stack;
using std::vector;
using std::queue;

//给定一个嵌套的整型列表。设计一个迭代器，使其能够遍历这个整型列表中的所有整数。
//
//列表中的项或者为一个整数，或者是另一个列表。


class NestedInteger {
    public:
      // Return true if this NestedInteger holds a single integer, rather than a nested list.
        bool isInteger() const;

      // Return the single integer that this NestedInteger holds, if it holds a single integer
      // The result is undefined if this NestedInteger holds a nested list
        int getInteger() const;

      // Return the nested list that this NestedInteger holds, if it holds a nested list
      // The result is undefined if this NestedInteger holds a single integer
        const vector<NestedInteger> &getList() const;
};



class NestedIterator {

    void flatten(const vector<NestedInteger> & nestedList)
    {
        for (const NestedInteger & ni: nestedList)
        {
            if (ni.isInteger())
                que.push(ni.getInteger());
            else
                flatten(ni.getList());
        }
    }

    queue<int> que;
public:
    NestedIterator(vector<NestedInteger> &nestedList) {
        flatten(nestedList);
    }

    int next() {
        int res = que.front();
        que.pop();
        return res;
    }

    bool hasNext() {
        return !que.empty();
    }
};
#endif //ALGORITHMS_Q341_NESTED_LIST_H
