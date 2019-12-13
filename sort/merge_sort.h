//
// Created by 97406 on 2019/12/13.
//

#ifndef ALGORITHMS_MERGE_SORT_H
#define ALGORITHMS_MERGE_SORT_H


//然后对左右两部分进行合并，合并过程中采用3个指针i, j, k
//[l, k)为原数组中的有序部分，[k, r]为原数组尚未排序的部分。
//[l, i)为左半区已经合并的部分，(mid + 1, j)为又半区已经合并的部分。
template <typename T>
void __merge_left_and_right(T arr[], int l, int r, int mid)
{
    T *arr_part_copy = new T[r-l+1];
    for (int x = l; x <= r; x ++)
        arr_part_copy[x - l] = arr[x];
    int i = l;
    int j = mid + 1;
    int k = l;
    while (k <= r)
    {
        if (i > mid)
        {
            arr[k] = arr_part_copy[j -l];
            j ++;
        }
        else if (j > r)
        {
            arr[k] = arr_part_copy[i - l];
            i ++;
        }
        else if (arr_part_copy[i - l] < arr_part_copy[j - l])
        {
            arr[k] = arr_part_copy[i - l];
            i++;
        }
        else
        {
            arr[k] = arr_part_copy[j - l];
            j++;
        }
        k++;
    }

    delete [] arr_part_copy;
}

//归并排序：首先对数组进行复制，复制的数组分成[l, p], (p, r]两部分（初始时l=0, r=n-1）,不断递归直至每个区间均为有序即只有一个元素
template <typename T>
void __merge_sort(T arr[], int l, int r)
{
    if (l>=r)
        return;
    int mid = (l+r)/2;
    __merge_sort(arr, l, mid);
    __merge_sort(arr, mid+1, r);
    if (arr[mid] > arr[mid + 1])     //对于近乎有序的数组，这条语句可以大大加快排序的速度。
        __merge_left_and_right(arr, l, r, mid);
}




template <typename T>
void merge_sort(T arr[], int n)
{
    __merge_sort(arr, 0, n - 1);

}

#endif //ALGORITHMS_MERGE_SORT_H




//自底向上的归并排序
//先从一个元素开始，两两进行merge操作，直到全部排序。
template <typename T>
void merge_sort_bottom_up(T arr[], int n)
{
    int size = 1; //每一步merge半区间的元素数量, [i, i+size-1], [i + size, i + 2 * size -1]
    for (size = 1; size <= n; size *=2 )
    {
        for (int i = 0; (i + size) < n; i += 2*size)   //若i+size>=n即此时已经没有右半区，无需merge
        {
            int right;
            right = std::min(n-1, i + 2*size-1);    //保证右区间的末尾在范围之内。
            __merge_left_and_right(arr, i, right, i+size-1);

        }
    }

}