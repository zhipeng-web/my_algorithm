//
// Created by china on 2024/5/28.
//
#include "vector"
using namespace std;
class Solution {
public:
    long long maxArrayValue(vector<int>& nums) {
        int n = nums.size();
        long long temp = nums.back(); //暂存最大值
        for(int i=n-2;i>=0;i--){ //从最右边开始遍历，若是nums[i]>当前最大元素，则更新最大元素的和
            if(temp>=nums[i]){
                temp += nums[i];
            } else{
                temp = nums[i];
            }
        }
        return temp;
    }
};