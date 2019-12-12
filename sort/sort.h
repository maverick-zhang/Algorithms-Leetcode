//
// Created by 97406 on 2019/12/12.
//

#ifndef ALGORITHMS_SORT_H
#define ALGORITHMS_SORT_H

#include <ctime>
#include <random>
#include <iostream>

using namespace std;

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
        swap(arr[min_index], arr[i]);
    }
}

template <typename T>
double time_costing_test(void (*sort_func) (T *, int), T arr[], int n)
{
    clock_t start = clock();
    sort_func(arr, n);
    clock_t end = clock();


    return (double) (end - start) / CLOCKS_PER_SEC;
}


//生产n个元素的随机数组，随机数的范围[left, right]
int * gen_test_case(int n, int left, int right)
{
    int * arr = new int[n];
    srand(time(nullptr));
    for (int i = 0; i < n; i++)
    {
        arr[i] = rand() % (right - left + 1) + left;
    }
    return arr;
}


template <typename T>
bool if_sorted(T arr[], int n)
{
    for (int i = 0; i < n-1; i++)
    {
        if (arr[i] > arr[i+1])
            return false;
    }
    return true;
}

#endif //ALGORITHMS_SORT_H
