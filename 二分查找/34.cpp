//
// Created by china on 2024/3/25.
//
#include "vector"
#include "iostream"
using namespace std;
class Solution {
public:
    int leftIndex = -2;
    int rightIndex = -2;//
    void findLeft(vector<int>& nums, int target){
        int left=0, right = nums.size() - 1;
        int mid;
        while (left <= right){
            mid = left + (right - left)/2;
            if(nums[mid]>=target){
                right = mid - 1;
                leftIndex = right;
            } else{
                left = mid + 1;
            }
        }
    }
    void findRight(vector<int>& nums, int target){
        int left = 0, right = nums.size()-1;
        int mid;
        while (left <= right){
            mid = left + (right - left);
            if(nums[mid]>target){
                right = mid - 1;
            } else{
                left = mid + 1;
                rightIndex = left;
            }
        }
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        findLeft(nums, target);
        findRight(nums,target);
        if(leftIndex == -2 || rightIndex == -2){//数组中没有target
            return {-1,-1};
        }
        if (rightIndex - leftIndex > 1) return {leftIndex + 1, rightIndex -1};
        return {-1, -1};
    }
};

int main(){
    Solution s;
    vector<int> a;
    vector<int>b = {2,2};
    a = s.searchRange(b,3);

    return 0;
};