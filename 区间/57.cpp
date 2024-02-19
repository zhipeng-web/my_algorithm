//
// Created by china on 2024/1/22.
//
# include "iostream"
# include "vector"
# include "algorithm"
using namespace std;
class Solution {
public:
    static bool cmp(vector<int> a, vector<int> b){
        return a[0]<b[0];
    }
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        intervals.push_back(newInterval);
        int n = intervals.size();
        sort(intervals.begin(), intervals.end(),cmp);
        vector<vector<int>> answer;
        answer.push_back(intervals[0]);
        for(int i=1;i<n;i++){
            if(answer.back()[1]>=intervals[i][0]){
                answer.back()[1] = max(answer.back()[1], intervals[i][1]);
            } else{
                answer.push_back(intervals[i]);
            }
        }
        return answer;
    }
};