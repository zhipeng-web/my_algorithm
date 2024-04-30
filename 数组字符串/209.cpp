//
// Created by china on 2024/4/30.
//
#include "iostream"
#include "vector"
using namespace std;
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int answer = INT_MAX;
        int slow=0,fast=0,sum=nums[0];
        while (fast<nums.size()){
            if(sum<target){
                fast++;
                if(fast>=nums.size()){
                    break;
                }
                sum+=nums[fast];
            } else if(sum>=target){
                answer = min(answer, fast-slow+1);
                sum-=nums[slow];
                slow++;
            }
        }
        if(answer == INT_MAX){
            answer = 0;
        }
        return answer;
    }
};