//
// Created by china on 2024/1/7.
//
#include "iostream"
#include "vector"
#include "unordered_map"
using namespace std;
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        unordered_map<int, int> rows;
        unordered_map<int, int> cols;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(matrix[i][j] == 0){
                    rows[i]++;
                    cols[j]++;
                }
            }
        }
        for(auto it=rows.begin(); it!=rows.end();it++){
            for(int i=0;i<n;i++){
                matrix[it->first][i] = 0;
            }
        }
        for(auto it=cols.begin(); it!=cols.end();it++){
            for(int i=0;i<m;i++){
                matrix[i][it->first] = 0;
            }
        }
    }
};