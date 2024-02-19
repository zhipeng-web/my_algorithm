//
// Created by china on 2023/12/13.
//
#include "iostream"
#include "vector"
#include "algorithm"
using namespace std;
class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();
        int result = 0;
        int left=0, right=n-1;
        int pre=0, suf=0;
        while (left<=right){
            pre = max(pre, height[left]);
            suf = max(suf, height[right]);
            if(pre<suf){
                result += pre-height[left];
                left++;
            } else{
                result += suf-height[right];
                right--;
            }
        }
        return result;
    }
};
