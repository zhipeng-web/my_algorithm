//
// Created by china on 2024/6/17.
//
#include "vector"
#include "string"
using namespace std;
class Solution {
public:
    bool isValid(int row, int col, char val, vector<vector<char>>& board){
        //判断行是否重复
        for(int i=0;i<9;i++){
            if(board[row][i] == val){
                return false;
            }
        }
        //判断列是否重复
        for(int j=0;j<9;j++){
            if(board[j][col] == val){
                return false;
            }
        }
        //判断9宫格是否重复
        int startRow = (row/3) * 3;
        int startCol = (col/3) * 3;
        for(int i=startRow;i<startRow+3;i++){
            for(int j=startCol;j<startCol+3;j++){
                if(board[i][j] == val){
                    return false;
                }
            }
        }
        return true;
    }
    bool backtrace(vector<vector<char>>& board){
        for(int i=0;i<board.size();i++){//遍历行
            for(int j=0;j<board[0].size();j++){//遍历列
                if(board[i][j] == '.'){//如果没有填数字
                    for(char ch='1';ch<='9';ch++){//尝试填数字1～9，看哪个合适
                        if(isValid(i, j, ch, board)){
                            board[i][j] = ch;
                            if(backtrace(board)) return true;//找到一组合适的立即返回
                            board[i][j] = '.';
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }
    void solveSudoku(vector<vector<char>>& board) {
        backtrace(board);
    }
};