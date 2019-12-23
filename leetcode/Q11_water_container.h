//
// Created by maverick on 2019/12/23.
//

#ifndef ALGORITHMS_Q11_WATER_CONTAINER_H
#define ALGORITHMS_Q11_WATER_CONTAINER_H

//给定 n 个非负整数 a1，a2，...，an，每个数代表坐标中的一个点 (i, ai) 。在坐标内画 n 条垂直线，垂直线 i 的两个端点分别为 (i, ai) 和 (i, 0)。找出其中的两条线，使得它们与 x 轴共同构成的容器可以容纳最多的水。
//
//说明：你不能倾斜容器，且 n 的值至少为 2。
//

#include <vector>
using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {

        //解题思路：使用两个指针i和j分别从左右两边开始, [0, i)和(j, n-1]为已经遍历的部分
        //在遍历的过程中计算面积并更新面积的最大值，下一次移动高度小的一边
        //证明:指针当前位置的面积为(j-i)*min(height[j])即height[j] < height[i]，那么当j--之后,相当于(i+1, j)...(j-1, j)这些
        //指针对将不会再被遍历到，即需要证明这些区间(p, j)的面积都小于当前的(i, j)时的面积。i<p<j
        //面积都必将小于等于(j-p)*height[j] < (j-i)*height[j]
        int i = 0, j = height.size()-1;
        int max_area = 0;
        int temp = 0;
        while (i < j)
        {
            temp = (j - i) * min(height[i], height[j]);
            if (max_area < temp)
                max_area = temp;
            if (height[i] < height[j])
                i ++;
            else
                j --;
        }
        return max_area;
    }
};

#endif //ALGORITHMS_Q11_WATER_CONTAINER_H
