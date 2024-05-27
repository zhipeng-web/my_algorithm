//
// Created by china on 2024/5/27.
//
#include "iostream"
#include "vector"
#include "algorithm"
using namespace std;
class Solution {
public:
    static bool cmp(pair<int,int> a, pair<int,int> b){
        return a.second>b.second;
    }
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        int answer=0;
        sort(worker.begin(),worker.end(),greater<int>());
        vector<pair<int,int>> works;
        for (int i = 0; i < difficulty.size(); ++i) { //工作利润数组
            works.push_back({difficulty[i], profit[i]});
        }
        sort(works.begin(),works.end(), cmp);
        int i=0,j=0;//i代表worker索引，j代表利润索引
        while (i<worker.size() && j<works.size()){
            if(worker[i]>=works[j].first){
                answer+=works[j].second;
                i++;
            } else{
                j++;
            }
        }
        return answer;
    }
};