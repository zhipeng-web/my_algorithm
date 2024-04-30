//
// Created by china on 2024/3/5.
//
#include "vector"
using namespace std;
class Solution {
public:
    int rows, cols;
    void dfs(vector<vector<char>>& board, int x, int y){
        if(x<0 || x >=rows || y<0 || y>=cols || board[x][y] !='O'){
            return;
        }
        board[x][y] = 'A';
        dfs(board,x + 1, y);
        dfs(board,x -1, y);
        dfs(board, x, y + 1);
        dfs(board, x, y - 1);
    }
    void solve(vector<vector<char>>& board) {
        rows = board.size();
        if(rows == 0)
            return;
        cols = board[0].size();
        for(int i=0;i<rows; i++){
            dfs(board, i, 0);
            dfs(board, i, cols - 1);
        }
        for(int j=1;j<cols -1 ;j++){
            dfs(board,0, j);
            dfs(board, rows - 1, j);
        }

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (board[i][j] == 'A') {
                    board[i][j] = 'O';
                } else if (board[i][j] == 'O') {
                    board[i][j] = 'X';
                }
            }
        }
    }
};