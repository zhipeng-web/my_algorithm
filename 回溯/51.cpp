//
// Created by china on 2024/6/17.
//
#include "vector"
#include "string"
using namespace std;
class Solution {
public:
    vector<vector<string>> res;
    void backtrace(vector<string>& chessboard, int row, int n){
        if(row == n){
            res.push_back(chessboard);
            return;
        }
        for (int i = 0; i < n; ++i) {
            if(isValid(chessboard, row,i,n)){
                chessboard[row][i] = 'Q';
                backtrace(chessboard, row+1, n);
                chessboard[row][i] = '.';
            }
        }
    }
    bool isValid(vector<string>& chessboard, int row, int col, int n){
        //判断列
        for(int i=0;i<row;i++){
            if(chessboard[i][col] == 'Q') return false;
        }

        //判断两条对角线
        // 45度
        for(int i=row-1, j = col-1;i>=0 && j>=0;i--,j--){
            if(chessboard[i][j] == 'Q') return false;
        }

        //135度
        for(int i=row-1, j = col+1;i>=0 && j<n;i--,j++){
            if(chessboard[i][j] == 'Q') return false;
        }
        return true;
    }
    vector<vector<string>> solveNQueens(int n) {
        res.clear();
        vector<string > chessboard(n, string(n, '.')); //初始棋盘。未放皇后
        backtrace(chessboard, 0, n);
        return res;
    }
};