//
// Created by maverick on 2019/12/17.
//

#ifndef ALGORITHMS_QUICK_FIND_H
#define ALGORITHMS_QUICK_FIND_H

#include <cassert>


//并查集
//功能：对数据（索引值）维护一个指向父节点索引的数组, 对于根节点，其父节点为其自身。因此对于两个数据点
//可以根据根节点是否相同，来判断两个数据是否处于同一个集合（即数据集），或者是否是连接的。
//并查集的最简单实现即为通过一个数组记录着每个数据的父节点索引。
class UnionFind_QF
{

private:
    int * root;    //root数组为每个数据（索引值）的根索引，因此通过root[index]可以快速查找到根节点。
    int size;
public:
    explicit UnionFind_QF (int n)
    {
        assert(n>0);
        root = new int[n];
        size = n;
        for (int i = 0; i < size ; ++i) {
            root[i] = i;
        }
    }

    ~UnionFind_QF()
    {
        delete [] root;
    }


    //查找索引index的根节点的索引值
    int find(int index)
    {
        assert(index >= 0 and index < size);
        return root[index];
    }

    //判断两个节点是否相连，即两个节点是否具有相同的根节点
    bool is_connected(int p, int q)
    {
        int p_root, q_root;
        p_root = find(p);
        q_root = find(q);
        return p_root == q_root;
    }

    //把两个孤立的数据集链接在一起。
    //p和q不一定是两个数据集的根节点, 但是要遍历其中一个数据集使其所有的数据的父节点都为另一个数据集的根节点
    void connect(int p, int q)
    {
        int p_root = find(p);
        int q_root = find(q);

        if (p_root == q_root)
            return;

        for (int i = 0; i <size ; ++i) {
            if (root[i] == p_root)
                root[i] = q_root;
        }
    }


};

#endif //ALGORITHMS_QUICK_FIND_H
