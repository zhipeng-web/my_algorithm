//
// Created by china on 2023/12/11.
//
#include "iostream"
#include "vector"
using namespace std;
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int answer = 1, index;
        for(int i=0;i<nums.size();i++){
            answer *= nums[i];
            if(nums[i]==0){
                index = i;
                break;
            }
        }
        if(answer == 0){
            answer = 1;
            for(int j=0;j<nums.size();j++){
                if(j!=index){
                    answer *=nums[j];
                }else{
                    continue;
                }
            }
            nums.assign(nums.size(),0);
            nums[index] = answer;
        }else{
            for(int j=0;j<nums.size();j++){
                nums[j] = answer/nums[j];
            }
        }
        return nums;
    }
};

