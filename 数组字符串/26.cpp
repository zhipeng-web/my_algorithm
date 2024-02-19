//
// Created by china on 2023/11/23.
//
#include "vector"
#include "iostream"
using namespace std;
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n=nums.size();
        if(n==0){
            return 0;
        }
        int fast=1, slow=1;
        while (fast<n){
            if(nums[fast] != nums[fast-1]){
                nums[slow++] = nums[fast];
            }
            fast++;
        }
    }
};
