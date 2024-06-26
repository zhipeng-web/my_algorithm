//
// Created by china on 2024/6/26.
//
#include "functional"
#include "vector"
using namespace std;
class Solution {
public:
    int countArrangement(int n) {
        vector<int> memo(1<<n, -1);//-1表示还没有计算过
        function<int(int)> dfs = [&](int s)->int{
            if(s == (1<<n) - 1){ //只剩下了一个元素
                return 1;
            }
            int res = memo[s];
            if(res != -1){//之前计算过
                return -1;
            }
           res = 0;
            int i = __builtin_popcount(s) + 1; // 计算当前 s 中已经设置为 1 的位数加 1，表示当前考虑放置第 i 个位置的数。
            for(int j=1;j<=n;j++){
                if((s >> (j - 1) & 1) == 0 && (i % j == 0 || j % i == 0)){ // (s >> (j - 1) & 1) == 0检查第 j 位是否为 0，即该位置未被使用。
                    res += dfs(s | (1 << (j - 1)));
                }
            }
            return res;
        };
        return dfs(0);
    }
};