//
// Created by china on 2024/1/10.
//
#include "iostream"
#include "vector"
using namespace std;
class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int m = board.size(), n = board[0].size();
        int assist[m+2][n+2]; //辅助数组
        for(int i=0;i<=m+1;i++){
            assist[i][0] = assist[i][n-1] = 2; //辅助数组第一列和最后一列设置为2
        }
        for(int i=0;i<=n+1;i++){
            assist[0][i] = assist[m-1][i] = 2; //第一行和最后一行设置为2
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                assist[i+1][j+1] = board[i][j]; // 将原始数组内容拷贝到辅助数组
            }
        }
        int direction[8][2] = {{-1,-1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0},{1,1}}; //8个方位
        for(int i=1;i<m+1;i++){
            for(int j=1;j<n+1;j++){
                int flag_live = 0;// 周围活细胞个数
                int flag_dead = 0;// 周围死细胞个数
                for(int k=0;k<8;k++){
                    if(assist[i + direction[k][0]][j + direction[k][1]] == 1){
                        flag_live++;
                    } else if(assist[i + direction[k][0]][j + direction[k][1]] == 0){
                        flag_dead++;
                    }
                }
               if(flag_live<2 || flag_live>3){
                   board[i-1][j-1] = 0;
               }
               if(flag_live == 3){
                   board[i-1][j-1] = 1;
               }
            }
        }
    }
};