//
// Created by china on 2024/1/7.
//
#include "iostream"
#include "vector"
using namespace std;
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        for(int i=0;i<n;i++){
            for(int j=0;j<=i;j++){
                if(i==j) continue;
                else{
                    int temp = matrix[i][j];
                    matrix[i][j] = matrix[j][i];
                    matrix[j][i] = temp;
                }
            }
        }
        int left=0, right=n-1;
        while (left<=right){
            for(int i=0;i<n;i++){
                int temp = matrix[i][left];
                matrix[i][left] = matrix[i][right];
                matrix[i][right] = temp;
            }
            left++;
            right--;
        }
    }
};