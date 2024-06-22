//
// Created by china on 2024/6/18.
//
#include "iostream"
using namespace std;
class Solution {
public:
    string minimizeResult(string expression) {
        int index = expression.find('+');//+号索引
        int n = expression.size();
        int sum = INT_MAX;
        string ans;

        for (int i = 0; i < index; ++i) {
            for (int j = index+1; j < expression.size(); ++j) {
                int left = (i==0 ? 1: stoi(expression.substr(0,i))); //+号左边的数
                //括号里面的数
                int mid  = stoi(expression.substr(i,index-i)) + stoi(expression.substr(index+1, j-index));
                int right = (j==n-1?1: stoi(expression.substr(j + 1, n - j - 1)));
                int temp = left * mid * right;
                if(temp<sum){
                    sum = temp;
                    ans = expression.substr(0, i) + "(" + expression.substr(i, j - i + 1) + ")" + expression.substr(j + 1, n - j - 1);
                }
            }
        }
        return ans;
    }
};