//
// Created by china on 2024/5/14.
//
#include "vector"
#include "unordered_map"
#include "queue"
using namespace std;
class Solution {
public:
    struct numAndFrequency{
        int num;
        int frequency;

        numAndFrequency(int a, int b) : num(a),frequency(b){}

        bool operator< (const numAndFrequency &other) const{ //按照频率降序排序
            return frequency<other.frequency;
        }
    };
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> hash;
        for(int num:nums){ //构建相应结构体
            hash[num]++;
        }
        priority_queue<numAndFrequency> queue;
        for(auto it : hash){
            queue.push(numAndFrequency(it.first, it.second));
        }
        vector<int> answer;
        while (k>0){
            answer.push_back(queue.top().num);
            queue.pop();
            k--;
        }
        return answer;
    }
};