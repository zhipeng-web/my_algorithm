//
// Created by china on 2024/6/29.
//
#include "iostream"
#include "vector"
#include "unordered_map"
using namespace std;
class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        int record[60] = {0}; // <time[i]对60的余数，计数>
        int ans = 0;
        for (int i = 0; i < time.size(); ++i) {
            int temp = (60 - (time[i] % 60)) % 60; //计算机time[i]需要补多少余数，两次60取余是为了应对time[i]等于60倍数的情况
            ans += record[temp];
            record[time[i]]++; //当当前time[i]插入hash
        }
        return ans;
    }
};