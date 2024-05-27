//
// Created by china on 2024/5/23.
//
#include "vector"
#include "unordered_map"
#include "algorithm"
using namespace std;
class Solution {
public:
    int longestEqualSubarray(vector<int>& nums, int k) {
        unordered_map<int,vector<int>> myMap;
        int n = nums.size();
        int max_num = 0;
        for (int i = 0; i < n; ++i) {//每个元素的下标集合
            myMap[nums[i]].push_back(i);
        }
        for(auto it:myMap){
            auto vec = it.second;//索引集合
            for(int i=0,j=0;j<vec.size();j++){//vec[i],vec[j]代表一个元素出现的索引位置,从左到右计算区间{vec[i],vec[j]}的最长等值子数组
                while (vec[j] - vec[i] - (j-i)>k){
                    i++;
                }
                max_num = max(max_num,j-i+1);
            }
        }
        return max_num;
    }
};