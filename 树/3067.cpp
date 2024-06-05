//
// Created by china on 2024/6/4.
//
#include "vector"
#include "iostream"
#include "functional"
using namespace std;
class Solution {
public:
    vector<int> countPairsOfConnectableServers(vector<vector<int>>& edges, int signalSpeed) {
        int n = edges.size() + 1; //节点个数
        vector<vector<pair<int,int>>> g(n); //图的邻接表形式
        for (auto &item:edges) {
            int x = item[0],y = item[1], wt = item[2];
            g[x].push_back({y,wt});
            g[y].push_back({x,wt}); //存入邻居和权重
        }
        /**
         * 深度优先，寻x为根节点的每一个子树有几个符合要求的节点,
           fa避免节点与父节点相同，形成环路
         */
        function<int(int, int, int)> dfs = [&](int x, int fa, int sum) -> int{
            //
            int cnt = sum%signalSpeed == 0;
            for(auto &[y,wt]:g[x]){
                if(y!=fa){
                    cnt += dfs(y,x,sum+wt);
                }
            }
            return cnt;
        };

        vector<int> ans(n);
        for (int i = 0; i < n; ++i) {
            int sum = 0;
            for(auto &[y,wt]:g[i]){
                int cnt = dfs(y,i,wt);
                ans[i] += cnt * sum;
                sum += cnt;
            }
        }
        return ans;
    }
};