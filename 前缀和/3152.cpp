//
// Created by china on 2024/7/3.
//
#include "iostream"
#include "vector"
using namespace std;
class Solution {
public:
    vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {
        int m = queries.size(), n = nums.size();
        int pre_sum[n];
        pre_sum[0] = 1; //默认第一个元素奇偶性不同
        for (int i = 1; i < n; ++i) {
            //相邻元素奇偶性不同，前缀和+1，否则保持不变
            if((nums[i] % 2 == 0 && nums[i-1] % 2 == 0) ||  (nums[i] % 2 != 0 && nums[i-1] % 2 != 0)){ //奇偶性一致
                pre_sum[i] = pre_sum[i-1];
            } else{
                pre_sum[i] = pre_sum[i-1] + 1;
            }
        }
        vector<bool> ans;
        for (auto query : queries) {
           if(pre_sum[query[1]] - pre_sum[query[0]] == query[1] - query[0]){
               //如果pre_sum[j] - pre_sum[i] == j - i
               //则区间[i,j]每一对相邻元素都是两个奇偶性不同的数字
               ans.push_back(true);
           } else{
               ans.push_back(false);
           }
        }
        return ans;
    }
};