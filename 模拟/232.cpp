//
// Created by china on 2024/4/22.
//
#include "stack"
using namespace std;
class MyQueue {
private:
    stack<int> pr;
    stack<int> be;
    int peak;//栈顶元素
public:
    MyQueue() {

    }
    //一个正常栈存放元素，遇到队列pop()时，将正常栈pr全部遍历一遍，最后一个元素就是队列头元素，然
    void push(int x) {
        pr.push(x);
        if(pr.size()==1){ //栈顶元素初始化
            peak = x;
        }
    }

    int pop() {
        while (!pr.empty()){
            be.push(pr.top());
            pr.pop();
        }
        int temp = be.top();
        be.pop();
        if(!be.empty()){ //出栈时，栈顶元素可能会改变，更新一下
            peak = be.top();
        }
        while ((!be.empty())){//将辅助栈元素存入正常栈，顺带清空辅助栈
            pr.push(be.top());
            be.pop();
        }
        return temp;
    }

    int peek() {
        return peak;
    }

    bool empty() {
        return pr.empty();
    }
};