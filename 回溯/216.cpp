//
// Created by china on 2024/6/11.
//
#include "vector"
#include "algorithm"
#include "numeric"
using namespace std;
class Solution {
public:
    vector<int> path;
    vector<vector<int>> ans;
    void backTrace(int k, int n, int start){
        if(path.size() == k && accumulate(path.begin(), path.end(), 0) == n){
            ans.push_back(path);
            return;
        }
       if(path.size()>k) return;//容量不符合要求。return
        for (int i = start; i <=9 ; ++i) {
            path.push_back(i);
            backTrace(k,n,i+1);
            path.pop_back();
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        backTrace(k,n,1);
        return ans;
    }
};