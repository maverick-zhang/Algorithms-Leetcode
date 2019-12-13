//
// Created by 97406 on 2019/12/12.
//

#ifndef ALGORITHMS_SORT_AUX_FUNC_H
#define ALGORITHMS_SORT_AUX_FUNC_H

#include <ctime>
#include <random>
#include <iostream>

using namespace std;

template <typename T>
double time_costing_test(void (*sort_func) (T *, int), T arr[], int n)
{
    clock_t start = clock();
    sort_func(arr, n);
    clock_t end = clock();


    return (double) (end - start) / CLOCKS_PER_SEC;
}

//判断是否为有序数组，返回布尔值。
template <class T>
bool if_sorted(T arr[], int n)
{
    for (int i = 0; i < n-1; i++)
    {
        if (arr[i] > arr[i+1])
            return false;
    }
    return true;
}


#endif //ALGORITHMS_SORT_AUX_FUNC_H
