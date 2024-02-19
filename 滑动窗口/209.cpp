//
// Created by china on 2023/12/22.
//
#include "iostream"
#include "vector"
using namespace std;
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int slow = 0, fast = 0;
        int sum = 0, n=nums.size();
        while (sum<target && fast<n){
            sum+=nums[fast];
            fast++;
        }
        if(sum<target){
            return 0;
        }
        int ans = fast - slow ;
        while (fast<n){
            sum -= nums[slow];
            slow++;
            while (sum<target && fast<n){
                sum+=nums[fast];
                fast++;
            }
            if(sum>=target){
                ans = min(ans, fast - slow);
            }
        }
        while (slow<n){
            sum -= nums[slow];
            slow++;
            if(sum>=target){
                ans = min(ans, fast - slow);
            }
        }
        return ans;
    }
};