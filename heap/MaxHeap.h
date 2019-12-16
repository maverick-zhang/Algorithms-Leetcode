//
// Created by maverick on 2019/12/14.
//

#ifndef ALGORITHMS_MAXHEAP_H
#define ALGORITHMS_MAXHEAP_H

#include <cassert>
#include <algorithm>
#include <vector>

using std::vector;
template <typename Item>
//大顶堆：堆顶元素为最大值，其数据结构为一颗完全二叉树，且满足二叉树的父节点比两个子节点的值都要大
//用大小为n+1的线性表来构成一颗n个元素的完全二叉树，其中线性表的第0位置为空。
//性质:索引为i的元素，其父节点索引为i/2, 左子节点为2*i, 右子节点索引为2*i+1;最后一个叶节点索引为end,则最后一个非叶节点索引为end/2;
class MaxHeap
{
private:
    int capacity;  //堆的容量
    int count;     //当前堆的元素个数
    Item * items;    //储存元素的线性表
    void shift_up(int k)
    {
        while (k/2 > 0 and items[k/2] < items[k])
        {
            std::swap(items[k/2], items[k]);
            k /= 2;
        }
    }

    void shift_down(int k)
    {
        while (2*k<=count)
        {
            int j = 2*k;
            if (j+1<=count and items[j+1] > items[j])
                j++;
            if (items[k] < items[j])
            {
                std::swap(items[k], items[j]);
                k = j;
            }
            else
                break;
        }
    }

    //对数组进行建堆
    //最后一个叶节点为索引count，最后一个非叶的索引为count/2
    //建堆的过程为：叶节点符合堆，建堆从最后一个非叶节点开始，对没一个非叶节点进行shift_down操作。
    void heapify()
    {
        for (int i = count/2; i >0 ; i--) {
            shift_down(i);
        }

    }

public:
    explicit MaxHeap (int n)
    {
        assert(n>0);
        items = new Item[n+1];
        capacity = n;
        count = 0;
    }

    explicit MaxHeap(vector<Item> & vt, int capacity_)
    {
        assert(capacity_ >= vt.size());
        items = new Item[capacity_ + 1];
        for (int i = 1; i <= vt.size(); ++i) {
            items[i] = vt[i-1];
        }
        capacity = capacity_;
        count = vt.size();
        heapify();
    }

    ~MaxHeap(){delete [] items;}


    bool insert(Item item)
    {
        if (count == capacity)
            return false;
        items[count+1] = item;
        count ++;
        shift_up(count);
        return true;
    }

    Item pop()
    {
        assert(count > 0);
        Item val = items[1];
        std::swap(items[1], items[count]);
        count --;
        shift_down(1);
        return val;
    }

    bool is_empty()
    {
        return count==0;
    }
};

#endif //ALGORITHMS_MAXHEAP_H
