//
// Created by china on 2024/6/29.
//
#include "iostream"
#include "vector"
#include "unordered_map"
using namespace std;
class Solution {
public:
    int num_sum(int num){
        int res = 0;
        while (num){
            res += num % 10;
            num/=10;
        }
        return res;
    }
    int maximumSum(vector<int>& nums) {
        unordered_map<int,int> record; //<数位，索引>
        int ans = INT_MIN;
        for (int i = 0; i < nums.size(); ++i) {
            int temp = num_sum(nums[i]);
            if(record.find(temp) != record.end()){ //更新ans
                ans = max(ans, nums[i] + nums[record[temp]]);
                //更新hash
                if(nums[i] > nums[record[temp]]){
                    record[temp] = i;
                }
                continue;
            }
            //没有hash记录，插入
            record[temp] = i;
        }
        return ans==INT_MIN?-1:ans;
    }
};