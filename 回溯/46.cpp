//
// Created by china on 2024/6/16.
//
#include "vector"
using namespace std;
class Solution {
public:
    vector<vector<int>> ans;
    vector<int> path;
    void backtrace(vector<int>& nums, vector<bool>& used){
        if(path.size()==nums.size()){
            ans.push_back(path);
            return;
        }

        for (int i=0; i < nums.size(); ++i) {
            if(used[i] == true) continue; //当前元素使用过，跳过
            used[i] = true;
            path.push_back(nums[i]);
            backtrace(nums, used);
            path.pop_back();
            used[i] = false;
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        ans.clear();
        path.clear();
        vector<bool> used(nums.size(), false);
        backtrace(nums, used);
        return ans;
    }
};