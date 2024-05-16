//
// Created by china on 2024/5/16.
//
#include "vector"
#include "algorithm"
#include <numeric>
using namespace std;

class Solution {
public:
    int findMinimumTime(vector<vector<int>>& tasks) {
        // 根据end_i对tasks进行排序
        sort(tasks.begin(), tasks.end(), [](auto &a,auto &b){
            return a[1]<b[1];
        });
        vector<bool> isRun(2000 + 1);
        int totalRun = 0;
        for(auto &t:tasks){
            int start = t[0], end = t[1], duration = t[2];
            int intervalRuns = accumulate(isRun.begin() + start, isRun.begin()+end + 1,0);
            if(duration>intervalRuns){
                // 已运行时刻不足以支持该任务的时长
                duration -= intervalRuns;  //  剩余需要运行的时刻
                // 逆序填充未运行时刻
                for(int j=end;j>=start && duration>0;j--){
                    if(!isRun[j]){
                        isRun[j] = true;
                        duration--;
                        totalRun++;
                    }
                }
            }
        }
        return totalRun;
    }
};