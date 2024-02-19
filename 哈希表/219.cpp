//
// Created by china on 2024/1/14.
//
#include "vector"
#include "unordered_map"
using namespace std;
class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int,int> cnt;
        int n = nums.size();
        for(int i=0;i<n;i++){
           if(cnt.find(nums[i])!=cnt.end() && (i - cnt[nums[i]]) <= k){
               return true;
           }
           cnt[nums[i]] = i;
        }
        return false;
    }
};