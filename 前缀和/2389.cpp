//
// Created by china on 2024/7/2.
//
#include "vector"
#include "algorithm"
using namespace std;
class Solution {
public:
    int binary(vector<int> &nums, int target){
        int left = 0;
        int right = nums.size()-1;
        while (left<=right){
            int mid = left +(right-left)/2;
            if(nums[mid] < target){
                left = mid + 1;
            } else{
                right = mid-1;
            }
        }
        return left;
    }
    vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<int> ans(queries.size());
        vector<int> pre_sum(n);
        pre_sum[0] = nums[0];
        // 计算前缀和
        for (int i = 1; i < n; ++i) {
            pre_sum[i] = pre_sum[i-1] + nums[i];
        }
        //构造答案
        for (int i = 0; i < queries.size(); ++i) {
           ans[i] = binary(pre_sum, queries[i]+1);
        }
        return ans;
    }
};