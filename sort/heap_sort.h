//
// Created by maverick on 2019/12/16.
//

#ifndef ALGORITHMS_HEAP_SORT_H
#define ALGORITHMS_HEAP_SORT_H

#include <algorithm>



//堆排序：首先对数组进行一次heapify,使其满足大顶堆，然后堆顶和堆尾的元素，此时最后一个元素即是有序的
//然后进行shift_down,再次交换堆定和堆尾（此时的堆已经不包含已经有序的部分）
//由于数组的索引从0开始，因此对于索引为i的节点，其父节点为（i-1）/2，其左子树为2*i+1，右子树为2*i+2


template <typename T>
//对索引为k的节点进行一次shift_down, count为堆中元素的个数。
void shift_down(T arr[], int count, int k)
{
    int j;
    int val = arr[k];
    while (2*k+1<count)
    {
        j = 2 * k + 1;
        if ((j+1)<count and arr[j] < arr[j+1])
            j ++;
        if (val >= arr[j])
            break;
//        std::swap(arr[k], arr[j]);
        arr[k] = arr[j];
        k = j;
    }
    arr[k] = val;
}


template <typename T>
//最后一个叶节点的索引为n-1,最后一个非叶节点为（n-1）/2
void heapify(T arr[], int n)
{
    for (int i = (n-1)/2; i >= 0 ; i--) {
        shift_down(arr, n, i);

    }

}


template <typename T>
void heap_sort(T arr[], int n)
{
    using std::swap;

    heapify(arr, n);
    for (int i = n-1; i >0 ; i--) {
        swap(arr[0], arr[i]);
        shift_down(arr, i, 0);
    }


}



#endif //ALGORITHMS_HEAP_SORT_H
