//
// Created by china on 2024/6/26.
//
#include "vector"
using namespace std;
class Solution {
public:
    static const int mod = 1e9 + 7;
    int specialPerm(vector<int>& nums) {
        int n = nums.size();
        int u = (1<<n) - 1;
        vector<vector<long long>> memo(u,  vector<long long>(n, -1));
        auto dfs = [&](auto&& dfs, int s, int i) -> long long {
            if(s==0){
                return 1;//找到一个排列
            }
            auto& res = memo[s][i];
            if(res != -1){
                return res;
            }
            res = 0;
            for (int j = 0; j < n; ++j) {
                if((s>>j & 1) && (nums[i] % nums[j] == 0 || nums[j] % nums[i] == 0)){
                    res += dfs(dfs,  s ^ (1 << j), j);
                }
            }
            return res;
        };
        long long ans = 0;
        for (int i = 0; i < n; i++) {
            ans += dfs(dfs, u ^ (1 << i), i);
        }
        return ans % 1'000'000'007;

    }
};