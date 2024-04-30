//
// Created by china on 2024/3/25.
//
#include "iostream"
#include "vector"
#include "algorithm"
using namespace std;
class Solution {
public:
    int quickSelect(vector<int> &nums, int k){
        int pivot = nums[rand() % nums.size()]; //选择枢纽
        vector<int> big, equal,small;
        for(auto num:nums){
            if(num > pivot){
                big.push_back(num);
            } else if(num<pivot){
                small.push_back(num);
            } else{
                equal.push_back(num);
            };
        }
        if (k<=big.size()){  // 第 k 大元素在 big 中，递归划分
            return quickSelect(big, k);
        }
        // 第 k 大元素在 small 中，递归划分
        if (nums.size() - small.size() < k)
            return quickSelect(small, k - nums.size() + small.size());
        return pivot;
    }
    int findKthLargest(vector<int>& nums, int k) {
        return quickSelect(nums,k);
    }
};