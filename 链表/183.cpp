//
// Created by china on 2023/11/27.
//
#include "iostream"
#include "vector"
using namespace std;
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        vector<int> copy(nums);
        for(int i=0;i<copy.size();i++){
            nums[(i + k)%nums.size()] = copy[i];
        }
    }
};