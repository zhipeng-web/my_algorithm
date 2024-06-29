//
// Created by china on 2024/6/29.
//
#include "iostream"
#include "vector"
#include "unordered_map"
using namespace std;
class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        unordered_map<int, int> record;// <num，计数>
        int ans = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if(record[k-nums[i]] > 0){ //i左边有等于k-nums[i]的数，则ans++， 技术--
                record[k-nums[i]]--;
                ans++;
            } else{
                record[nums[i]]++;
            }
        }
        return ans;
    }
};