//
// Created by maverick on 2020/1/7.
//

#ifndef ALGORITHMS_Q401_BINARY_WATCH_H
#define ALGORITHMS_Q401_BINARY_WATCH_H

//二进制手表顶部有 4 个 LED 代表小时（0-11），底部的 6 个 LED 代表分钟（0-59）。
//
//每个 LED 代表一个 0 或 1，最低位在右侧。

#include <vector>
#include <string>
#include <cmath>
using namespace std;

//小时灯最多同时三个点亮
//分钟灯最多同时5点亮
//总计4+6 = 10个点, 求出num个点的任意组合，在计算时间是否符合

class Solution {
    vector<string> res;

    vector<bool> led;

    void calc_time(int num, int i)
    {
        if (num == 0)
        {
            int hour = 0, minute = 0;
            for (int j = 0; j < 4; ++j) {
                if (led[j])
                    hour += pow(2, j);
            }
            for (int k = 4; k < 10; ++k) {
                if (led[k])
                    minute += pow(2, k - 4);
            }
            if (hour < 12 and minute < 60)
            {
                string time = to_string(hour) + ":";
                if (minute < 10)
                    time += "0";
                time += to_string(minute);
                res.push_back(time);
            }
            return;
        }

        for (int l = i; l < 10; ++l) {
            led[l]  = true;
            calc_time(num - 1, l + 1);
            led[l] = false;
        }
    }
public:
    vector<string> readBinaryWatch(int num) {
        led = vector<bool> (10, false);

        calc_time(num, 0);

        return res;

    }
};

#endif //ALGORITHMS_Q401_BINARY_WATCH_H
