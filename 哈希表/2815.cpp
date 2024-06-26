//
// Created by china on 2024/6/25.
//
#include "vector"
#include "algorithm"
using namespace std;

class Solution {
public:
    int find_max(int n){
        int temp = 0;
        while(n){
            temp = max(temp,n%10);
            n/=10;
        }
        return temp;
    }

    int maxSum(vector<int> &nums) {
        int ans = -1;
        vector<int> max_val(10, INT_MIN); //定义映射表，存储0~9每个数字对应当前遍历位置的最大值
        for (int v: nums) {
            int max_d = find_max(v);//当前元素的最大数位
            ans = max(ans, v + max_val[max_d]);//更新ans
            max_val[max_d] = max(max_val[max_d], v);//更新映射表
        }
        return ans;
    }
};