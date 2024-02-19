//
// Created by china on 2024/1/3.
//
#include "iostream"
#include "vector"
using namespace std;
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int row [9][10] = {0};
        int col [9][10] = {0};
        int box [9][10] = {0};
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                if(board[i][j]==' '){
                    continue;
                }
                int cur_number = board[i][j] - '0';
                if(row[i][cur_number]){
                    return false;
                }
                if(col[j][cur_number]){
                    return false;
                }
                if(box[(i/3) * 3 + (j/3)][cur_number]){
                    return false;
                }
                row[i][cur_number] = 1;
                col[j][cur_number] = 1;
                box[(i/3) * 3 + (j/3)][cur_number] = 1;
            }
        }
        return true;
    }
};