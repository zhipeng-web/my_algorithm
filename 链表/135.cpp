//
// Created by china on 2023/12/12.
//
#include "iostream"
#include "vector"
#include "algorithm"
using namespace std;
class Solution {
public:
    int candy(vector<int> &ratings) {
        int n = ratings.size();
        if(n==1){
            return 1;
        }
        vector<int> left;
        for(int i=0;i<n;i++){
            if(i>0 && ratings[i]<=ratings[i-1]){
                left[i]=1;
            } else{
                left[i] = left[i-1]+1;
            }
        }
        int right = 0, ret=0;
        for(int i=n-1;i>=0;i--){
            if(i<n-1 && ratings[i]>ratings[i+1]){
                right++;
            } else{
                right=1;
            }
            ret += max(left[i],right);
        }
        return ret;
    }
};
