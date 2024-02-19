//
// Created by china on 2024/1/31.
//
#include "string"
#include "stack"
#include "set"
#include "iostream"
using namespace std;
class Solution {
public:
    string zhong_to_hou(string s){
        string houzhui = "";
        stack<char> assist;
        set<char> op = {'+','-','*','/','(',')'};
        for(int i=0;i<s.length();i++){
            char a = s[i];
            if(op.find(a)==op.end()){
                houzhui += a;
                continue;
            } else{
                if(a == '(') {
                    assist.push(a);
                    continue;
                }
                if(a == ')' || a == '+' || a == '-'){
                    while (!assist.empty()){
                        char b = assist.top();
                        if(b == '('){
                            assist.pop();
                            break;
                        }
                        else{
                            houzhui += b;
                            assist.pop();
                        }
                    }
                    if(a!=')') assist.push(a);
                }
                if(a == '*' || a=='/'){
                    while (!assist.empty()){
                        char b = assist.top();
                        if(b == '+' || b == '-' || b=='('){
                            if(b=='(') assist.pop();
                            break;
                        } else{
                            houzhui+=b;
                            assist.pop();
                        }
                    }
                    assist.push(a);
                }
            }
        }
        while (!assist.empty()){
            houzhui += assist.top();
            assist.pop();
        }
        return houzhui;
    }
    int calculate(string s) {
        string hou = zhong_to_hou(s);
    }
};

int main(){
    Solution solution;
    string s = "a+b*(c-d)-e/f";
    cout<<solution.zhong_to_hou(s);
    return 0;
}