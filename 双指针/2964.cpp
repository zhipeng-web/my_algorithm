//
// Created by china on 2024/7/1.
//
#include "vector"
#include "unordered_map"
using namespace std;
class Solution {
public:
    int divisibleTripletCount(vector<int>& nums, int d) {
        if(nums.size()<3) return 0;
        unordered_map<int, int> record; // 记录索引k之前，nums[i]和nums[j]相加对d余数的统计情况
        record[(nums[0] %d + nums[1]%d) % d]++;
        int ans = 0;
        for (int k = 2; k < nums.size(); ++k) {
            int temp = (d - nums[k]%d)%d; //查看nums[k]所需的数
            ans += record[temp];
            for (int i = 0; i < k; ++i) { //每遍历一个元素，就需要入hash一次
                record[(nums[i] %d + nums[k]%d) % d]++;
            }
        }
        return ans;
    }
};