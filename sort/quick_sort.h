//
// Created by maverick on 2019/12/13.
//

#ifndef ALGORITHMS_QUICK_SORT_H
#define ALGORITHMS_QUICK_SORT_H

#include <algorithm>

template <typename T>
//[l+1, j]为小于val的部分， [j+1, i)为大于等于val的部分， [i, r]为尚未分区的部分。
//索引i在遍历的过程中，大于等于val的部分不动，i++, 小于val的部分和arr[j+1]进行交换，同时j++
int __partition(T arr[], int l, int r)
{
    T val = arr[l];    //为了避免快排对近乎有序的数组进行排序时时间复杂度退化为n^2，可以随机选择一个点作为val
    int j = l;         //方式为swap(arr[ rand() % ( r - l + 1) + l], arr[l])，即用区间内的随机一个元素和起始元素交换。
    for(int i = l + 1; i <= r; i++)
    {
        if (arr[i] < val)
        {
            std::swap(arr[i], arr[j+1]);
            j++;
        }
    }
    std::swap(arr[l], arr[j]);
    return j;  //这里的返回值不是很严谨，其实应该返回j-1，但是直接返回j不影响结果，而且避免j-1的越界问题。


}

//双路快排：为了避免存在大量相同值数组排序过程效率底下，使用两个指针i,j分别为左右两个区间内下一个需要进行遍历的元素。
//[l+1, i)为左区间都小于等于val,(j, r]为右区间都大于等于val
template <typename T>
int __partition2(T arr[], int l, int r)
{

    swap(arr[rand()%(r-l+1)+l], arr[l]);
    T val = arr[l];

    int i = l+1;
    int j = r;
    while (true)
    {
        while (i <= r and arr[i] < val)i++;
        while (j >= l and arr[j] > val)j--;
        if (i>j)
            break;
        swap(arr[i], arr[j]);
        i++;
        j--;
    }
    swap(arr[l], arr[j]);
    return j;
}


//三路快速排序，维护三个指针lt,gt,i,把数组分成三个区间[l+1, lt], [lt+1, i), [gt, r]
//三个区间分别代表：小于val的部分，等于val的部分，和大于val的部分。
template <typename T>
void __partition3(T arr[], int l, int r)
{
    if (l>=r)
        return;
    swap(arr[rand()%(r-l+1)+l], arr[l]);
    T val = arr[l];
    int lt = l;
    int gt = r + 1;
    int i = l+1;
    while (i < gt)
    {
        if (arr[i] > val)
        {
            swap(arr[i], arr[gt-1]);
            gt--;
        }
        else if (arr[i] < val)
        {
            swap(arr[i], arr[lt+1]);
            i++;
            lt++;
        }
        else
            i++;
    }
    swap(arr[l], arr[lt]);
    __partition3(arr, l, lt - 1);
    __partition3(arr, gt, r);

}


//对区间为[l, r]的元素进行快排
//首先把区间分成[l, p], [p+1, r]两个部分，其中右半区都大于等于val， 左搬去小于val。
template <typename T>
void  __quick_sort(T arr[], int l, int r)
{
    if (l>=r)
        return;
    int p = __partition(arr, l, r);
    __quick_sort(arr, l, p);
    __quick_sort(arr, p+1, r);

}


template <typename T>
//快速排序：选取第一个元素val，把数组分为左右两个区间，左区间都小于val, 右区间都大于等于val
void quick_sort(T arr[], int n)
{
    srand(time(nullptr));
    __quick_sort(arr, 0, n-1);
}


template <typename T>
void quick_sort_three_ways(T arr[], int n)
{
    srand(time(nullptr));
    __partition3(arr, 0, n-1);

}
#endif //ALGORITHMS_QUICK_SORT_H
