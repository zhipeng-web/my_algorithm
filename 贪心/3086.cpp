//
// Created by china on 2024/7/4.
//
#include "iostream"
#include "vector"
#include "algorithm"
using namespace std;
class Solution {
public:
    long long minimumMoves(vector<int>& nums, int k, int maxChanges) {
        vector<int> pos;
        int c = 0; // nums 中连续的 1 长度
        for (int i = 0; i < nums.size(); ++i) {
            if(nums[i] == 0) continue;
            pos.push_back(i);// 记录 1 的位置
            c = max(c,1);
            if(i>0 && nums[i-1] == 1){
                if(i>1 && nums[i-2]==1){
                    c = 3; // 有 3 个连续的 1
                } else{
                    c=2; // 有 2 个连续的 1
                }
            }
        }

        c = min(c,k);
        if(maxChanges >= k-c){
            // 其余 k-c 个 1 可以全部用两次操作得到
            return max(c-1,0) + (k-c) * 2;
        }

        int n = pos.size();
        vector<long long> sum(n+1);

        for (int i = 0; i < n; ++i) { //计算所有1之间的距离
            sum[i+1] = sum[i] + pos[i];
        }

        long long ans = LLONG_MAX;
        // 除了 maxChanges 个数可以用两次操作得到，其余的 1 只能一步步移动到 pos[i]
        // 只需要计算剩下 k - maxChanges个1的距离即可
        int size = k - maxChanges;
        for (int right = size; right <= n; right++) {
            // s1+s2 是 j 在 [left, right) 中的所有 pos[j] 到 index=pos[(left+right)/2] 的距离之和
            int left = right - size;
            int i = left + size/2;
            long long index = pos[i];
            long long s1 = index * (i - left) - (sum[i] - sum[left]);
            long long s2 = sum[right] - sum[i] - index * (right-i);
            ans = min(ans, s1 + s2);
        }
        return ans + maxChanges * 2;
    }
};