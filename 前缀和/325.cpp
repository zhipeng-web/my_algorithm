//
// Created by china on 2024/6/9.
//
#include "vector"
#include "iostream"
#include "unordered_map"
using namespace std;
class Solution {
public:
    int maxSubArrayLen(vector<int>& nums, int k) {
      long long sum = 0;
      int ans = 0;
      unordered_map<long long, int> map; //记录前缀和首次出现的索引位置
      map[0] = -1;
      for(int i=0;i<nums.size();i++){
          sum += nums[i];
          if(map.find(sum - k) != map.end()){ //如果有某个前缀和和当前前缀和刚好可以得到k，ans进行更新
              ans = max(ans, i - map[sum-k]);
          }
          //只保存最小索引，确保子数组最长
          if(map.find(sum) == map.end()){
              map[sum] = i;
          } else{
              map[sum] = min(map[sum],i);
          }
      }
        return ans;
    }
};