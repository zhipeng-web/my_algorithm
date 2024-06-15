//
// Created by china on 2024/6/15.
//
#include "vector"
#include "algorithm"
using namespace std;
class Solution {
public:
    int maximumBeauty(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int left = 0;
        int right = 0;
        int ans = 0;
        while (right<nums.size()){
            if(nums[right] - nums[left]>2 * k){
                ans = max(ans, right - left);
                left++;
                continue;
            }
            right++;
        }
        ans = max(ans, right - left);
        return ans;
    }
};