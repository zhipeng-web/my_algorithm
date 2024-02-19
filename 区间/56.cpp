//
// Created by china on 2024/1/16.
//
#include "algorithm"
#include "vector"
using namespace std;
class Solution {
public:
    static bool cmp(vector<int> a, vector<int> b){
        return a[0]<b[0];
    }
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> answer;
        sort(intervals.begin(), intervals.end(), cmp);
        int n = intervals.size();
        answer.push_back(intervals[0]);
        for(int i=1;i<n;i++){
            if(answer.back()[1]>= intervals[i][0]){
                answer.back()[1] = max(answer.back()[1], intervals[i][1]);
            } else{
                answer.push_back(intervals[i]);
            }
        }
        return answer;
    }
};