//
// Created by china on 2024/7/1.
//
#include "iostream"
#include "vector"
#include "unordered_map"
using namespace std;
class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        int pre_max = 0;//下标i之前的,和i组合的最大收入下标
        int ans = INT_MIN;
        for (int i = 1; i < values.size(); ++i) {
            ans = max(ans, values[i] + values[pre_max] + pre_max - i);
            if(values[i] + i> values[pre_max] + pre_max){ //更新最大索引
                pre_max = i;
            }
        }
        return ans;
    }
};