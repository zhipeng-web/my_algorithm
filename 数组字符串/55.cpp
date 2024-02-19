//
// Created by china on 2023/11/28.
//
#include "iostream"
#include "vector"
#include "algorithm"
using namespace std;
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n=nums.size();
        int max_step=0;
        for(int i=0;i<n;i++){
            if(i>max_step){
                break;
            }
            max_step = max(max_step, i+nums[i]);
            if(max_step>=n-1){
                return true;
            }
        }
        return false;
    }
};