//
// Created by china on 2024/6/22.
//
#include "vector"
#include "algorithm"
using namespace std;
class Solution {
public:
    static bool cmp(pair<int, int> &a, pair<int, int> &b){ //升序排序
        return a.first>b.first;
    }
    int maxDistance(vector<vector<int>>& arrays) {
        int ans = 0;
        vector<pair<int, int>> max_nums;//每个数组的最大值,和数组编号
        vector<pair<int, int>> min_nums;//每个数组的最小值
        for (int i = 0; i <arrays.size() ; ++i) {
            max_nums.push_back({arrays[i].back(),i});
            min_nums.push_back({arrays[i].front(),i});
        }
        //进行排序，将值按照从大到小排序
        sort(max_nums.begin(), max_nums.end(), cmp);
        sort(min_nums.begin(), min_nums.end(), cmp);

        for (int i = 0; i < max_nums.size(); ++i) {
            for (int j = min_nums.size()-1; j >=0; j--) { //将每个数组的最大值和最小值(排除当前数组)比较一下
                if(max_nums[i].second != min_nums[j].second){
                    ans = max(ans, max_nums[i].first - min_nums[j].first);
                    break;
                }
            }
        }
        return ans;
    }
};