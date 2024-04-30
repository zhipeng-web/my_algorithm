//
// Created by china on 2024/3/5.
//
#include "vector"
#include "queue"
using namespace std;
class Solution {
public:
   int dir[4][2] = {0, 1, 1, 0, -1, 0, 0, -1}; // 四个方向
    void bfs(vector<vector<char>>& grid, vector<vector<bool>>& visited, int x, int y){
        queue<pair<int, int>> myQueue;//广度优先队列
        myQueue.push({x, y});
        while (!myQueue.empty()){
            for(int i=0;i<4;i++){
                int nextx = x + dir[i][0];
                int nexty = y + dir[i][1];
                if(nextx < 0 || nextx >= grid.size() || nexty<0 || nexty>= grid[0].size()) continue; //坐标越界
                if(!visited[nextx][nexty] && grid[nextx][nexty] == '1'){
                    visited[nextx][nexty] = true;
                    myQueue.push({nextx, nexty});
                }
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<bool>> visited = vector<vector<bool>>(m, vector<bool>(n, false));
        int answer = 0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(!visited[i][j] && grid[i][j] == '1'){
                    answer++;
                    bfs(grid, visited, i, j);
                }
            }
        }
        return answer;
    }
};