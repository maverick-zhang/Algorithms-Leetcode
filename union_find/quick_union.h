//
// Created by maverick on 2019/12/17.
//

#ifndef ALGORITHMS_QUICK_UNION_H
#define ALGORITHMS_QUICK_UNION_H

#include <cassert>

//quick_find的并查集在判断两个数据是否是同一个集合时是O(1)操作，但是把两个数据集进行归并的时候是O(n)的复杂度
//quick_union将归并的复杂度降为O(lgn)，同时进行查询的操作也是近乎于O(1)的操作
//其所采取的优化为：把root数组更换为parent数组，即仅仅保存数据的父节点索引。这样数据集就形成了一个树结构、
//额外维护一个数组elm_size，表示元素集中元素的个数，在合并数据集的过程中，把小的数据集合并到大的数据集中不会增加树的高度
//合并的具体做法为把小数据集的根节点的父节点设置为大数据集的根节点。
//另外使用路径压缩降低树的高度，具体的做法为在find的过程中，如果父节点不是根节点，那么把该数据的父节点设置为父节点的父节点


class UnionFind_QU
{
private:
    int * parent;
    int * elm_size;

    int size;
public:
    explicit UnionFind_QU(int n)
    {
        assert(n>0);
        parent = new int[n];
        elm_size = new int[n];
        size = n;
        for (int i = 0; i < size; ++i) {
            parent[i] = i;
            elm_size[i] = 1;
        }
    }

    ~UnionFind_QU()
    {
        delete [] parent;
        delete [] elm_size;
    }

    //路劲压缩比较难以处理层数的问题
    int find(int index)
    {
        while (parent[index] != index)
        {
            //路径压缩
            //可以不用进行判断父节点是否为根节点，以下的语句也符合逻辑，因为根节点的父节点为其自身。
            parent[index] = parent[parent[index]];
            index = parent[index];
        }


        return index;
    }

    void connect(int p, int q)
    {

        assert(p>0 and p < size and q>0 and q<size);
        int p_root = find(p);
        int q_root = find(q);

        if (p_root == q_root)
            return;

        if (elm_size[p] < elm_size[q])
            parent[p_root] = q_root;
        else if(elm_size[p] > elm_size[q])
            parent[q_root] = p_root;
        else
        {
            parent[p_root] = q_root;
            elm_size[q_root] += elm_size[p_root];
        }
    }
};

#endif //ALGORITHMS_QUICK_UNION_H
