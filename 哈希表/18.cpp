//
// Created by china on 2024/5/8.
//
#include "vector"
#include "iostream"
#include "algorithm"
using namespace std;
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> answer;
        sort(nums.begin(), nums.end());
        for(int k=0;k<nums.size();k++){
            //剪枝
            if(nums[k] > target && nums[k]>=0){
                break;
            }
            //去重
            if(k>0 && nums[k] == nums[k-1]){
                continue;
            }
            for(int i=k+1;i<nums.size();i++){
                //二级剪枝
                if(long(nums[k] + nums[i]) > target && long(nums[k] + nums[i])>=0){
                    break;
                }
                //二级去重
                if(i>k+1 && nums[i] == nums[i-1]){
                    continue;
                }
                int left = i + 1;
                int right = nums.size()-1;
                while (right>left){
                    if(long(nums[k]) + long(nums[i]) + long(nums[left]) + long(nums[right]) > target){
                        right--;
                    } else if(long(nums[k]) + long(nums[i]) + long(nums[left]) + long(nums[right]) < target){
                        left++;
                    } else{
                        answer.push_back(vector<int>{nums[k],nums[i], nums[left], nums[right]});
                        //对left和right去重
                        while (right>left && nums[right] == nums[right-1]) right--;
                        while (right>left && nums[left] == nums[left+1]) left++;

                        //找到答案，收缩指针
                        right--;
                        left++;
                    }
                }
            }
        }
        return answer;
    }
};