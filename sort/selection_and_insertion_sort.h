//
// Created by 97406 on 2019/12/13.
//

#ifndef ALGORITHMS_SELECTION_AND_INSERTION_SORT_H
#define ALGORITHMS_SELECTION_AND_INSERTION_SORT_H


#include <algorithm>

//选择排序：循环遍历数组，找出未排序部分的最小值，并与未排序部分的第一个值进行交换
//[0. i)为已排序部分，[i, n)为尚未进行排序的部分
template <typename T>
void selection_sort(T arr[], int n)     //对arr数组进行选择排序，数组的大小为n。
{

    for (int i = 0; i < n; i++)
    {
        int min_index = i;              //min_index记录当前循环过程中的最小值的索引值。
        for (int j = i; j < n; j++)
        {
            if (arr[j] < arr[min_index])
                min_index = j;
        }
        std::swap(arr[min_index], arr[i]);
    }
}



//插入排序：从指针当前位置向前遍历，比较指针元素与遍历的元素值，若前者小：遍历的元素后移，否则停止，交换元素。
//[0, i)为已排序的部分，[i, n)为尚未排序的部分。
template <typename T>
void insertion_sort(T arr[], int n)
{
    T temp;
    int j;
    for (int i = 1; i < n; i++)
    {
        temp = arr[i];
        for (j = i; j > 0 ; j --)
        {
            if (temp < arr[j - 1])
                arr[j] = arr[j - 1];
            else
            {
                arr[j] = temp;
                break;
            }
        }
    }
}



#endif //ALGORITHMS_SELECTION_AND_INSERTION_SORT_H
