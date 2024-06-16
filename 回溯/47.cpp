//
// Created by china on 2024/6/16.
//
#include "vector"
#include "unordered_set"
#include "algorithm"
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
        unordered_set<int> hash;
        for (int i=0; i < nums.size(); ++i) {
            for (int i = 0; i < nums.size(); i++) {
                // used[i - 1] == true，说明同一树枝nums[i - 1]使用过
                // used[i - 1] == false，说明同一树层nums[i - 1]使用过
                // 如果同一树层nums[i - 1]使用过则直接跳过
                if (i > 0 && nums[i] == nums[i - 1] && used[i - 1] == false) {
                    continue;
                }
                if (used[i] == false) {
                    used[i] = true;
                    path.push_back(nums[i]);
                    backtrace(nums, used);
                    path.pop_back();
                    used[i] = false;
                }
            }
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        ans.clear();
        path.clear();
        sort(nums.begin(), nums.end());
        vector<bool> used(nums.size(), false);
        backtrace(nums, used);
        return ans;
    }
};