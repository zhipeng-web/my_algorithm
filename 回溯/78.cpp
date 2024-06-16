//
// Created by china on 2024/6/15.
//
#include "vector"
using namespace std;
class Solution {
public:
    vector<vector<int>> ans;
    vector<int> temp;
    void backtrace(vector<int> &nums,int start){
        ans.push_back(temp);
        for (int i = start; i < nums.size(); ++i) {
            temp.push_back(nums[i]);
            backtrace(nums, i+1);
            temp.pop_back();
        }
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        ans.clear();
        temp.clear();
        //放入空集
        backtrace(nums, 0);
        return ans;
    }
};