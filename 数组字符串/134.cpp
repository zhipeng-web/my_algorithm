//
// Created by china on 2023/12/11.
//
#include "iostream"
#include "vector"
#include "algorithm"
using namespace std;
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int flag = 0, n=gas.size(), index, min_g=INT_MAX;
        for(int i=0;i<n;i++){
            flag += gas[i] - cost[i];
            if(flag<min_g){
                min_g = flag;
                index = i;
            }
        }
        if(flag<0){
            return -1;
        }
        return (index + 1)%n;
    }
};