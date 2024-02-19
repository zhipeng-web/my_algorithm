//
// Created by china on 2024/1/22.
//
#include "iostream"
#include "stack"
#include "unordered_map"
using namespace std;
class Solution {
public:
    bool isValid(string s) {
        stack<char> left;
        unordered_map<char, char> assist = {{'(', ')'},{'[',']'},{'{','}'}};
        int n = s.length();
        for(int i=0;i<n;i++){
            if(s[i] == '(' || s[i] == '[' || s[i] == '{'){
                left.push(s[i]);
            } else{
                if(left.empty()){
                    return false;
                }
                char temp = left.top();
                left.pop();
                if(assist[temp] != s[i]){
                    return false;
                }
            }
        }
        return left.empty();
    }
};