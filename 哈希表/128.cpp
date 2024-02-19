//
// Created by china on 2024/1/14.
//
#include "vector"
#include "set"
#include "algorithm"
using namespace std;
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        set<int> hash; //无重复集合，去掉重复元素，并且自动排序
        vector<int> assist;//存放无重复集合的数组
        for(auto it=nums.begin();it!=nums.end();it++){
            hash.insert(*it);
        }
        for(auto it=hash.begin();it!=hash.end();it++){
            assist.push_back(*it);
        }
        int answer = 0, left = 0, n = assist.size();//left是连续子数组左边边界，right是右边边界
        for(int right = 0;right<n;right++){ //遍历无重复数组， 找到连续数组
            if(right==n-1 || assist[right+1] != assist[right] + 1 ){//子数组不连续或者数组已经遍历完成，更新最大子数组长度
                answer = max(answer, right - left + 1);
                left = right + 1;
            }
        }
        return answer;
    }
};