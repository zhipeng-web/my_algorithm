//
// Created by china on 2024/1/24.
//
#include "iostream"
#include "vector"
#include "algorithm"
using namespace std;
class MinStack {
    vector<int> x_stack;// 记录栈内元素
    vector<int> min_assist; //辅助数组，记录栈顶元素对应的最小值
public:
    MinStack() {
       min_assist.push_back(INT_MAX);
    }

    void push(int val) {
        x_stack.push_back(val);
        min_assist.push_back(min(val, min_assist.back()));//元素入栈，同时将此时栈内对应的最小元素记录下来
    }

    void pop() {
        if(!x_stack.empty()){
            x_stack.pop_back();
            min_assist.pop_back();
        }
    }

    int top() {
        return x_stack.back();
    }

    int getMin() {
        return min_assist.back();
    }
};