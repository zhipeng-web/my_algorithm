//
// Created by china on 2023/11/24.
//
#include "iostream"
#include "vector"
using namespace std;
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
      int length = nums.size();
      if(length<=2){
          return length;
      }
      int slow = 2, fast=2;
      while(fast<length){
          if(nums[fast]!=nums[slow-2]){
              nums[slow++] = nums[fast];
          }
          fast++;
      }
      return slow;
    }
};