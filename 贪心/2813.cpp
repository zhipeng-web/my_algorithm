//
// Created by china on 2024/6/13.
//
#include<iostream>
#include "algorithm"
#include "vector"
#include "stack"
#include "unordered_set"

using namespace std;
class Solution {
public:
    static bool cmp(vector<int> a, vector<int> b){
        return a[0]>b[0];
    }
    long long findMaximumElegance(vector<vector<int>>& items, int k) {
        sort(items.begin(), items.end(), cmp);
        long long ans=0;
        long long total_profit=0;
        stack<int> duplicate;//重复类别的利润
        unordered_set<int> visit; //访问过的类别
        for (int i = 0; i < items.size(); i++) {
            if(i<k){
                total_profit += items[i][0];
                if(!visit.insert(items[i][1]).second){ //插入失败，表示已经有相同类别的，将利润入stack
                    duplicate.push(items[i][0]);
                }
            } else if(!duplicate.empty() && visit.insert(items[i][1]).second){ //这个类别之前没有插入过，更新一下ans
                total_profit += items[i][0] - duplicate.top(); // 选一个重复类别中的最小利润替换
                duplicate.pop();
            }// else 比前面的利润小，而且类别还重复了，选它只会让 total_profit 变小，vis.size() 不变，优雅度不会变大
            ans = max(ans, total_profit +(long long) visit.size() * (long long) visit.size() );
        }

        return ans;
    }
};