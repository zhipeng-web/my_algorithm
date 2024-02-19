//
// Created by china on 2023/12/18.
//
#include "string"
using namespace std;
class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows==1){
            return s;
        }
        int step = numRows * 2 - 2;
        int index=0;
        int n=s.length();
        int add = 0;
        string ret;
        for(int i=0; i<numRows;i++){
            index = i;
            add = i*2;
            while (index < n){
                ret += s[index];
                add = step - add;
                index+=(i==0 || i==numRows -1)? step:add;
            }
        }
        return ret;
    }
};