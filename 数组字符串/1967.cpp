//
// Created by china on 2024/4/8.
//
#include "iostream"
#include "vector"
#include "string"
using namespace std;
class Solution {
public:
    int numOfStrings(vector<string>& patterns, string word) {
        int answer = 0;
        for(auto str:patterns){
            if(word.find(str)!=string::npos){
                answer++;
            }
        }
        return answer;
    }
};