//
// Created by china on 2023/12/6.
//
#include "iostream"
#include "vector"
#include "algorithm"
using namespace std;

class Solution {
public:
    int jump(vector<int>& nums) {
        int max_steps = 0, n=nums.size()-1, end=0, step=0;
        for(int i=0;i<n-1;i++){
            if(max_steps>=i){
                max_steps = max(max_steps, i+nums[i]);
                if(i == end){
                    end = max_steps;
                    step++;
                }
            }
        }
        return step;
    }
};