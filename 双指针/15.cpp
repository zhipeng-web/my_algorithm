//
// Created by china on 2023/12/22.
//
#include "iostream"
#include "vector"
#include "algorithm"
using namespace std;
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        for(int i=0;i<n;i++){
            if(i>0 && nums[i] == nums[i-1]){
                continue;
            }
            int second = i + 1;
            int third = n - 1;
            int target = -nums[i];
            for(second;second<n;second++){
                if(second > i+1 && nums[second] == nums[second-1]){
                    continue;
                }
                while (second<third && nums[second] + nums[third] > target){
                    third--;
                }
                if(second == third)
                {
                    break;
                }
                if (nums[second] + nums[third] == target){
                    ans.push_back({nums[i], nums[second], nums[third]});
                }
            }
        }
        return ans;
    }
};