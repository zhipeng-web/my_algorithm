//
// Created by china on 2024/7/1.
//
#include "iostream"
#include "vector"
#include "unordered_map"
#include "algorithm"
using namespace std;
class Solution {
public:
    int cnt(int num){
        string str = to_string(num);
        //翻转字符串
        reverse(str.begin(), str.end());
        //去除前导0
        int index = 0;
        while (index<str.size()){
            if(str[index] != '0') break;
            index++;
        }
        str = str.substr(index);
        if(str.size()==0){
            return num;
        }
        //转回数字
        return num - stoi(str);
    }
    int countNicePairs(vector<int>& nums) {
        // nums[i] + rev(nums[j]) == nums[j] + rev(nums[i]) 等价于 nums[i] - rev(nums[i]) == nums[j] - rev(nums[j])
        // temp =nums[i] - rev(nums[i]), hash存储nums[i] - rev(nums[i])的数量，一次遍历，碰到hash[temp]!=0,累加即可
        unordered_map<int ,int> record;
        int ans = 0;
        const int mod = 1e9 + 7;
        for (auto num : nums) {
            int temp = cnt(num);
            ans += record[temp];
            ans %= mod;
            record[temp]++;
        }
        return ans;
    }
};