//
// Created by china on 2024/1/25.
//
#include "iostream"
#include "string"
#include "stack"
using namespace std;
class Solution {
public:
    void calc(stack<int> &nums, stack<char> &ops){
        if(nums.size()<2 || ops.empty())
            return;
        int b = nums.top();nums.pop();
        int a = nums.top();nums.pop();
        char op = ops.top();ops.pop();
        nums.push(op == '+'? a+b:a-b);
    }
    void replace(string &s){
        int index = s.find(" ");
        while (index!=-1){
            s.replace(index,1,"");
            index = s.find(" ");
        }
    }
    int calculate(string s) {
        replace(s);
        stack<int> nums;
        nums.push(0);
        stack<char> ops;
        int n = s.size();
        for(int i=0;i<n;i++){
            char c = s[i];
            if(c == '(')
                ops.push(c);
            else if(c == ')'){
                while (!ops.empty()){
                    char op = ops.top();
                    if(op!='(')
                        calc(nums, ops);
                    else{
                        ops.pop();
                        break;
                    }
                }
            } else{
                if(isdigit(c)){
                    int cur_num = 0;
                    int j=i;
                    while (j<n && isdigit(s[j])){
                        cur_num = cur_num * 10 + (s[j++] - '0');
                    }
                    nums.push(cur_num);
                    i = j-1;
                } else{
                    if(i>0 && (s[i-1] == '(' || s[i-1] == '+' || s[i-1] == '-')){
                        nums.push(0);
                    }
                    // 有一个新操作要入栈时，先把栈内可以算的都算了
                    while(!ops.empty() && ops.top() != '(')
                        calc(nums, ops);
                    ops.push(c);
                }
            }
        }
        while (!ops.empty())
            calc(nums, ops);
        return nums.top();
    }
};