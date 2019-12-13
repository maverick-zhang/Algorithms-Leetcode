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
    __quick_sort(arr, 0, n-1);
}

#endif //ALGORITHMS_QUICK_SORT_H
