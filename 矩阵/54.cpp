//
// Created by china on 2024/1/5.
//
#include "iostream"
#include "vector"
using namespace std;
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        if(matrix.size()==0 || matrix[0].size()==0){
            return {};
        }
        vector<int> answer;
        int left=0, right=matrix[0].size()-1, top=0, botton=matrix.size()-1;
        while (left<=right && top<=botton){
            for(int column=left;column<=right;column++){
                answer.push_back(matrix[top][column]);
            }
            for(int row=top+1;row<=botton;row++){
                answer.push_back(matrix[row][right]);
            }
            if(left<right && top<botton){
                for(int column=right-1;column>left;column--){
                    answer.push_back(matrix[botton][column]);
                }
                for(int row=botton;row>top;row--){
                    answer.push_back(matrix[row][left]);
                }
            }
            left++;
            top++;
            right--;
            botton--;
        }
        return answer;
    }
};