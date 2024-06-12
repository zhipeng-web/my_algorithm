//
// Created by china on 2024/6/11.
//
#include "vector"
using namespace std;
class Solution {
public:
    int ans = 0;
    void dfs(vector<vector<char>>& board, vector<vector<int>>& visit, int x, int y){
        if(x<0 || x>=board.size() || y<0 || y>=board[0].size()) return; //坐标越界，返回
        if(visit[x][y]) return; //访问过，返回
        if(board[x][y] == '.') return; // 不是军舰return
        ans++;
        visit[x][y] = 1;
        // 不知道是水平还是垂直，所以两个方向都探测一下
        int tempY = y;
        while (tempY<board[0].size() && board[x][tempY] == 'X'){ //将军舰标记
            visit[x][tempY] = 1;
            tempY++;
        }
        int tempX = x;
        while (tempX<board.size() && board[tempX][y] == 'X'){ //将军舰标记
            visit[tempX][y] = 1;
            tempX++;
        }
//        dfs(board, visit, x+1, y);
//        dfs(board, visit,x,y+1);
//        dfs(board, visit, x+1, y+1);
    }
    int countBattleships(vector<vector<char>>& board) {
        int m = board.size();
        int n = board[0].size();
        vector<vector<int>> visit(m, vector<int>(n,0));
        for(int i = 0; i < m; ++i) {
            for(int j = 0; j < n; ++j) {
                if(!visit[i][j] && board[i][j] == 'X') {
                    dfs(board, visit, i, j);
                }
            }
        }
        return ans;
    }
};