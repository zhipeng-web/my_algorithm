//
// Created by china on 2024/5/16.
//
#include "vector"
#include "algorithm"
#include "iostream"
#include <numeric>
using namespace std;
class Solution {
public:
    long long numberOfWeeks(vector<int>& milestones) {
        // 耗时最长工作所需周数
        long long longest = INT_MIN;
        long long sum = 0;
        for(long long it:milestones){
            longest = max(longest, it);
            sum += it;
        }
        // 其余工作共计所需周数
        long long rest = sum-longest;
        if (longest > rest + 1){
            // 此时无法完成所耗时最长的工作
            return rest * 2 + 1;
        }
        else {
            // 此时可以完成所有工作
            return longest + rest;
        }
    }
};