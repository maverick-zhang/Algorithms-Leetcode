//
// Created by maverick on 2019/12/16.
//

#ifndef ALGORITHMS_INDEXMAXHEAP_H
#define ALGORITHMS_INDEXMAXHEAP_H

#include <cassert>
#include <algorithm>
#include <vector>

using std::vector;
template <typename Item>
//使用三个数组，一个保留原始的数据称之为items，一个为二叉树数组称之为index，其内容为data的索引，一个为reverse数组，其保存着index的反向索引.
//索引大顶堆：堆顶元素为最大值，其数据结构为一颗完全二叉树，且满足二叉树的父节点比两个子节点的值都要大
//用大小为n+1的线性表来构成一颗n个元素的完全二叉树，其中线性表的第0位置为空。
//性质:索引为i的元素，其父节点索引为i/2, 左子节点为2*i, 右子节点索引为2*i+1;最后一个叶节点索引为end,则最后一个非叶节点索引为end/2;
class IndexMaxHeap
{
private:
    int capacity;       //堆的容量
    int count;          //当前堆的元素个数
    int * index;        //index[i]=j，j为items数组的索引，即val = items[index[i]],index为一个二叉树。
    int * reverse;      //reverse[j] = i, index[i] = j, 即val= items[index[reverse[j]]] = items[j].
                        //性质：reverse[index[i]] = i. index[reverse[j]] = j.
    Item * items;       //储存元素的线性表

    void shift_up(int k)
    {
        while (k/2 > 0 and items[index[k/2]] < items[index[k]])
        {
            std::swap(index[k/2], index[k]);
            reverse[index[k/2]] = k/2;
            reverse[index[k]] = k;
            k /= 2;
        }
    }

    void shift_down(int k)
    {
        while (2*k<=count)
        {
            int j = 2*k;
            if (j+1<=count and items[index[j+1]] > items[index[j]])
                j++;
            if (items[index[k]] < items[index[j]])
            {
                std::swap(index[k], index[j]);
                reverse[index[k]] = k;
                reverse[index[j]] = j;
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
    explicit IndexMaxHeap (int n)
    {
        assert(n>0);
        items = new Item[n+1];
        index = new int[n+1]{0};
        reverse = new int[n+1] {0};
        capacity = n;
        count = 0;
    }

    explicit IndexMaxHeap(vector<Item> & vt, int capacity_)
    {
        assert(capacity_ >= vt.size());
        items = new Item[capacity_ + 1];
        index = new int [capacity_ + 1]{0};
        reverse = new int[capacity_+1]{0};

        for (int i = 1; i <= vt.size(); ++i) {
            items[i] = vt[i-1];
            index[i] = i;    //index[i] = j, reverse[j] = i
            reverse[i] = i;
        }
        capacity = capacity_;
        count = vt.size();


        heapify();
    }

    ~IndexMaxHeap(){
        delete [] items;
        delete [] index;
        delete [] reverse;
    }


    bool insert(Item item)
    {
        if (count == capacity)
            return false;
        items[count+1] = item;
        index[count+1] = count+1;
        reverse[count+1] = count + 1;
        count ++;
        shift_up(count);
        return true;
    }

    Item pop()
    {
        assert(count > 0);
        Item val = items[index[1]];
        std::swap(items[index[1]], items[index[count]]);
        reverse[index[1]] = 0;
        reverse[index[count]] = count;
        count --;
        shift_down(1);
        return val;
    }

    bool is_empty()
    {
        return count==0;
    }

    Item get_item(int i)
    {
        assert(i>=0 and i < count);
        return items[index[reverse[i+1]]];
    }
};


#endif //ALGORITHMS_INDEXMAXHEAP_H
