//
// Created by china on 2024/1/24.
//
#include <stack>
#include "iostream"
#include "unordered_map"
#include "vector"
#include "stdlib.h"
using namespace std;
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        int n = tokens.size();
        stack<string> assist;//辅助栈，保存计算结果
        for(int i=0;i<n;i++){
            if(tokens[i] == "*"){
                int a = atoi(assist.top().c_str());
                assist.pop();
                int b = atoi(assist.top().c_str());
                assist.pop();
                assist.push(to_string(a * b));
                continue;
            } else if(tokens[i] == "+"){
                int a = atoi(assist.top().c_str());
                assist.pop();
                int b = atoi(assist.top().c_str());
                assist.pop();
                assist.push(to_string(a + b));
                continue;
            } else if(tokens[i] == "/"){
                int a = atoi(assist.top().c_str());
                assist.pop();
                int b = atoi(assist.top().c_str());
                assist.pop();
                assist.push(to_string(b/a));
                continue;
            } else if(tokens[i] == "-"){
                int a = atoi(assist.top().c_str());
                assist.pop();
                int b = atoi(assist.top().c_str());
                assist.pop();
                assist.push(to_string(b-a));
                continue;
            } else{
                assist.push(tokens[i]);
            }
        }
        return atoi(assist.top().c_str());
    }
};