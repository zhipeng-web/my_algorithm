//
// Created by china on 2024/1/23.
//
#include "iostream"
#include "cstring"
#include "vector"
#include "stack"
using namespace std;
class Solution {
public:
    string simplifyPath(string path) {
        char *s = path.data();
        vector<string> strs;
        stack<string> assist;
        string answer="";
        char *token = strtok(s, "/"); //  按照/划分字符串
        while (token!= nullptr){
            strs.push_back(token);
            token = strtok(nullptr, "/");// 调用nullptr表示继续使用同一个字符串
        }
        for(auto it = strs.begin();it!=strs.end();it++){
            if(*it == ".." && !assist.empty()) assist.pop();
            if(*it!="." && *it != ".." && *it!="") assist.push(*it);
        }
        if(assist.empty()){
            answer = "/";
        } else{
            while (!assist.empty()){
                answer = "/" + assist.top() + answer;
                assist.pop();
            }
        }
        return answer;
    }
};