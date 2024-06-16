//
// Created by china on 2024/6/16.
//
#include "vector"
#include "unordered_set"
using namespace std;
class Solution {
public:
    vector<vector<int>> ans;
    vector<int> path;
    void backtrace(vector<int>& nums, int start){
        if(path.size()>=2) ans.push_back(path);
        unordered_set<int> hash;
        for (int i = start; i < nums.size(); ++i) { //当前path不为空，且nuns[i]<path最大元素，或者nums[i]已经在本层使用过了
            if((!path.empty() && nums[i]<path.back()) || hash.find(nums[i]) != hash.end()){
                continue;
            }
            path.push_back(nums[i]);
            hash.insert(nums[i]); // // 记录这个元素在本层用过了，本层后面不能再用了
            backtrace(nums, i+1);
            path.pop_back();
        }
    }
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        ans.clear();
        path.clear();
        backtrace(nums, 0);
        return ans;
    }
};