//
// Created by china on 2024/6/9.
//
#include "vector"
#include "iostream"
using namespace std;
class Solution {
public:
    vector<vector<int>> rec; //记忆化数组，记录（i，j）的值
    vector<int> val;
    int solve(int left, int right){ //求开区间(i,j)的最大值
        if(left>=right){
            return 0;
        }
        if(rec[left][right] != -1){
            return rec[left][right];
        }
        for (int i = left+1; i < right; ++i) {
            int sum = val[left] * val[right] * val[i];
            sum += solve(left,i) + solve(i, right);
            rec[left][right] = max(sum, rec[left][right]);
        }
        return rec[left][right];
    }
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        val.resize(n+2);
        for(int i=1;i<=n;i++){
            val[i] = nums[i-1];
        }
        val[0] = val[n+1] = 1;
        rec.resize(n + 2, vector<int>(n + 2, -1));
        return solve(0, n+1);
    }
};