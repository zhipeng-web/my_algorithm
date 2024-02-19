//
// Created by china on 2024/1/22.
//
#include "iostream"
#include "vector"
#include "algorithm"
using namespace std;
class Solution {
public:
    static bool cmp(vector<int> &a, vector<int> &b){
        return a[1]<b[1];
    }
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(), points.end(), cmp);
        int n = points.size();
        int index = points[0][1];
        int answer = 1;
        for(auto it = points.begin();it!=points.end();it++){
            if(it->front() > index){
                answer++;
                index = it->back();
            }
        }
        return answer;
    }
};