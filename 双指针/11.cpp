//
// Created by china on 2023/12/21.
//
#include "vector"
#include "algorithm"
#include "iostream"
using namespace std;
class Solution {
public:
    int maxArea(vector<int>& height) {
        int left=0, right=height.size()-1;
        int ans = 0;
        int area;
        while (left<right){
            area = (right - left) * min(height[left], height[right]);
            ans = max(area, ans);
            if(height[left] < height[right]){
                left++;
            } else{
                right++;
            }
        }
        return ans;
    }
};
