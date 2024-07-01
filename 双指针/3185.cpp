//
// Created by china on 2024/6/30.
//

#include "iostream"
#include "vector"
#include "unordered_map"
using namespace std;
class Solution {
public:
    long long countCompleteDayPairs(vector<int>& hours) {
        int ans = 0;
        unordered_map<int, int> record; //<对24小时余数，计数>
        for(auto hour:hours){
            ans += record[(24 - hour % 24) % 24];
            record[hour%24]++;
        }
        return ans;
    }
};