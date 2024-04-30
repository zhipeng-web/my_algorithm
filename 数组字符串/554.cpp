//
// Created by china on 2024/4/2.
//
#include "vector"
#include "iostream"
#include "unordered_map"
using namespace std;
class Solution {
public:
    int leastBricks(vector<vector<int>>& wall) { //穿过的砖最少，就是穿过发缝隙最多
        int count = 0;
        unordered_map<int, int> hash;//同一位置的缝隙数量
        for(int i=0;i<wall.size();i++){
            int sum = 0;
            for(int j=0;j<wall[i].size()-1;j++){
                sum += wall[i][j];
                hash[sum]++;
                count = max(count, hash[sum]);
            }
        }
        return wall.size() - count;
    }
};