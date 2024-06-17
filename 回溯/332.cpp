//
// Created by china on 2024/6/17.
//
#include "vector"
#include "string"
#include "unordered_map"
#include "map"
#include "algorithm"
#include "unordered_set"
using namespace std;

class Solution {
public:
    // unordered_map<出发机场, map<到达机场, 航班次数>> targets
    unordered_map<string, map<string, int>> targets;
    static bool cmp(vector<string> &a, vector<string>& b){
        for (int i = 0; i < a.size(); ++i) {
            if(a[i] != b[i]){
                return a[i]<b[i];
            }
        }
        return true;
    }
    bool backtrace(int n, vector<string>& result){ //n地点数
        if(result.size() == n+1){
            return true;
        }

        for(pair<const string, int>& target:targets[result[result.size() - 1]]){
            if(target.second>0){ //可以到达该机场
                result.push_back(target.first);
                target.second--;
                if(backtrace(n, result)) return true;
                result.pop_back();
                target.second++;
            }
        }
        return false;
    }
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        targets.clear();
        vector<string > res;
        for (const vector<string>& vec:tickets){
            targets[vec[0]][vec[1]]++;
        }
        res.push_back("JFK");
        backtrace(tickets.size(), res);
        return res;
    }
};