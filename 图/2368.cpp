//
// Created by china on 2024/5/31.
//
#include "vector"
#include "queue"
#include "set"
#include "unordered_map"
using namespace std;
class Solution {
public:
    int reachableNodes(int n, vector<vector<int>>& edges, vector<int>& restricted) {
        int ans = 0;
        set<int> restrict(restricted.begin(), restricted.end());
        unordered_map<int, vector<int>> edge; //key节点，value节点可以到达的所有节点集合
        vector<int>visited(n,0); //标记数组，记录是否访问
        for(auto it:edges){
            edge[it[0]].push_back(it[1]); //构造edge集合
            edge[it[1]].push_back(it[0]); //无向图所以要双向记录
        }
        queue<int> myQueue;
        myQueue.push(0);
        while (!myQueue.empty()){//广度遍历
            int cur_node = myQueue.front();
            myQueue.pop();
            ans++;
            for (int i = 0; i < edge[cur_node].size(); ++i) {
                if(visited[edge[cur_node][i]] || restrict.find(edge[cur_node][i])!= restrict.end()){
                    continue;//当前节点访问过或者是不可达节点，跳过
                }
                myQueue.push(edge[cur_node][i]);
            }
            visited[cur_node] = 1; //标记为已经访问
        }
        return ans;//
    }
};