//
// Created by china on 2024/5/22.
//
#include "vector"
#include "unordered_map"
#include "algorithm"
using namespace std;
class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        vector<vector<int>> ans(2);
        unordered_map<int,int> win; //记录参赛者胜利场数
        unordered_map<int,int> sum;//记录参赛者总场数
        for(auto it:matches){
            //记录参赛者胜利场数
            win[it[0]]++;
            win[it[1]] +=0;
            //记录参赛者总场数
            sum[it[0]]++;
            sum[it[1]]++;
        }
        for (auto it:win) {
            if(it.second == sum[it.first]){ //胜利场数与总场数相等
                ans[0].push_back(it.first);
            }
            if(it.second == sum[it.first]-1){ //胜利场数比总少一个
                ans[1].push_back(it.first);
            }
        }
        sort(ans[0].begin(), ans[0].end());
        sort(ans[1].begin(), ans[1].end());
        return ans;
    }
};