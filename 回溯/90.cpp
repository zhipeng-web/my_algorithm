//
// Created by china on 2024/6/16.
//
#include "vector"
#include "algorithm"
using namespace std;
class Solution {
public:
    vector<vector<int>> ans;
    vector<int> path;
    void backtrace(vector<int> &nums, int start, vector<bool> used){
        ans.push_back(path);
        for (int i = start; i < nums.size(); ++i) {
            // used[i - 1] == true，说明同一树枝candidates[i - 1]使用过
            // used[i - 1] == false，说明同一树层candidates[i - 1]使用过
            // 要对同一树层使用过的元素进行跳过
            if(i>0 && nums[i] == nums[i-1] && used[i-1]== false){ //剪枝操作，ans里面不入相同元素
                continue;
            }
            path.push_back(nums[i]);
            used[i] = true;
            backtrace(nums, i+1, used);
            path.pop_back();
            used[i] = false;
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<bool> used(nums.size(), false);//定义used数组
        ans.clear();
        path.clear();
        sort(nums.begin(), nums.end());
        backtrace(nums, 0, used);
        return ans;
    }
};