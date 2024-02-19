//
// Created by china on 2024/1/16.
//
#include "vector"
#include "iostream"
#include "algorithm"
using namespace std;
class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        int n = nums.size(),left = 0, right = 0;//左右指针，指向连续子数组的左右两端
        vector<string> answer;
        while (right < n){
            while ((right + 1) <n && (nums[right] + 1) == nums[right+1]){//判断下一个元素是否属于连续子数组
                right++;
            }
            if(nums[left] == nums[right]){ //区间长度为1和区间长度>2时的处理方式
                answer.push_back(to_string(nums[left]));
            } else{
                answer.push_back(to_string(nums[left]) + "->" + to_string(nums[right]));
            }
            left = right = right+1;//处理下一个子数组
        }

        return answer;
    }
};