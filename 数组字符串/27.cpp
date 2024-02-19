//
// Created by china on 2023/11/23.
//
#include "iostream"
#include "vector"
#include "algorithm"
using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int left=0, right = nums.size()-1;
        while(left<right){
            if(nums[left] == val){
                nums[left] = nums[right--];
            } else{
                left++;
            }
        }
        return left;
    }
};

