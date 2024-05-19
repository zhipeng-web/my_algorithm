//
// Created by china on 2024/5/16.
//
#include "vector"
#include "queue"
#include "algorithm"
using namespace std;

class MyQueue{
public:
    deque<int> que; //单调队列
    // 每次弹出的时候，比较当前要弹出的数值是否等于队列出口元素的数值，如果相等则弹出。
    // 同时pop之前判断队列当前是否为空。
    void pop(int value){
        if(!que.empty() && value == que.front()){
            que.pop_front();
        }
    }
    // 如果push的数值大于入口元素的数值，那么就将队列后端的数值弹出，直到push的数值小于等于队列入口元素的数值为止。
    // 这样就保持了队列里的数值是单调从大到小的了。
    void push(int value){
        while (!que.empty() && value>que.back()){
            que.pop_back();
        }
        que.push_back(value);
    }

    int getMaxNum(){
        return que.front();
    }

};

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> answer;
        MyQueue myQueue;
        for(int i=0;i<k;i++){
            myQueue.push(nums[i]);
        }
        answer.push_back(myQueue.getMaxNum());
        for(int i=k;i<nums.size();i++){
            myQueue.pop(nums[i-k]);
            myQueue.push(nums[i]);
            answer.push_back(myQueue.getMaxNum());
        }
        return answer;
    }
};