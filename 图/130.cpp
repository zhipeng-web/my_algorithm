//
// Created by china on 2024/3/5.
//
#include "vector"
using namespace std;
class Solution {
public:
    int dir[4][2] = {0, 1, 1, 0, -1, 0,0, -1};
    void dfs(vector<vector<char>>& board, vector<vector<bool>> & visited, int x, int y){
        for(int i=0;i<4;i++){
            int nextx = x + dir[i][0];
            int nexty = y + dir[i][1];
            if(nextx < 0 || nextx >= board.size() || nexty<0 || nexty>=board[0].size()) continue; //坐标越界
            if(!visited[nextx][nexty] && board[nextx][nexty] == 'O'){
                visited[nextx][nexty] = true;
                dfs(board, visited, nextx, nexty);
            }
        }
    }
    void solve(vector<vector<char>>& board) {
        int rows = board.size(), cols = board[0].size();
        vector<vector<bool>> visited = vector<vector<bool>> (rows, vector<bool>(cols, false));
        //将与边界上的O相连的O标记为true
        for(int i=0;i<cols;i++){
            if(board[0][i] == 'O' && !visited[0][i]){
                visited[0][i] = true;
                dfs(board, visited,0,i);
            }
            if(board[rows - 1][i] == 'O' && !visited[rows - 1][i]){
                visited[rows - 1][i] = true;
                dfs(board, visited,rows - 1,i);
            }
        }

        //将与边界上的O相连的O标记为true
        for(int j=1;j<rows - 1;j++){
            if(board[j][0] == 'O' && !visited[j][0]){
                visited[j][0] = true;
                dfs(board, visited, j, 0);
            }
            if(board[j][cols - 1] == 'O' && !visited[j][cols - 1]){
                visited[j][cols - 1] = true;
                dfs(board, visited, j, cols - 1);
            }
        }

        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                if(board[i][j] == 'O' && !visited[i][j])
                    board[i][j] = 'X';
            }
        }
    }
};