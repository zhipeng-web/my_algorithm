//
// Created by china on 2024/1/13.
//
#include "vector"
#include "unordered_map"
#include "algorithm"
using namespace std;
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
       unordered_map<int, int> hash;
       for(int i=0;i<nums.size();i++){
           auto it = hash.find(target - nums[i]);
           if(it!=hash.end()){
               return {i, it->second};
           }
           hash[nums[i]] = i;
       }
        return {};
    }
};