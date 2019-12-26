//
// Created by maverick on 2019/12/25.
//

#ifndef ALGORITHMS_Q202_HAPPY_NUMBER_H
#define ALGORITHMS_Q202_HAPPY_NUMBER_H

#include <unordered_set>
//#include <vector>


//
//编写一个算法来判断一个数是不是“快乐数”。
//
//一个“快乐数”定义为：对于一个正整数，每一次将该数替换为它每个位置上的数字的平方和，然后重复这个过程直到这个数变为 1，也可能是无限循环但始终变不到 1。如果可以变为 1，那么这个数就是快乐数。
//
//示例: 
//
//输入: 19
//输出: true
//解释:
//1^2 + 9^2 = 82
//8^2 + 2^2 = 68
//6^2 + 8^2 = 100
//1^2 + 0^2 + 0^2 = 1
using namespace std;
class Solution {
private:
    unordered_set<int> record;

public:
    bool isHappy(int n) {

        //如果出现无限循环，那么这个值一定在迭代的过程中出现过，只需要判断是否重复出现即可，否则进行无限的迭代

        if (record.find(n) != record.end())
            return false;
        record.insert(n);
        int sum = 0;
        while (n > 0)
        {
            sum += (n % 10) * (n % 10);
            n /= 10;
        }
        if (sum == 1)
            return true;
        else
            return isHappy(sum);

    }
};


#endif //ALGORITHMS_Q202_HAPPY_NUMBER_H
