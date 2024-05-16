//
// Created by china on 2024/5/14.
//
#include "iostream"
#include "vector"
#include "unordered_map"
using namespace std;
class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        int answer = 0;
        unordered_map<int,int> count_num;
        for(int num:tasks){//统计相同难度的任务有各有多少个
            count_num[num]++;
        }
        for(auto it:count_num){
            if(it.second<2){//相同难度的任务少于两个，则永远无法处理
                return -1;
            } else if(it.second % 3 == 0){ //任务个数刚好是3的倍数，花费最少时间it.second/3
                answer += it.second/3;
            }else if(it.second % 3 == 1){//任务个数%3=1，此时需要有2次只能处理两个任务，剩下每次处理3个，一共处理
                answer += (it.second-4)/3 + 2; // (it.second-4)/3 + 2的简化
            }else if(it.second % 3 == 2){//任务个数%3=2，此时需要有1次只能处理两个任务
                answer += it.second/3 + 1;
            }
        }
        // 简化版
//        for(auto it:count_num){
//            if(it.second<2){//相同难度的任务少于两个，则永远无法处理
//                return -1;
//            } else if(it.second % 3 == 0){ //任务个数刚好是3的倍数，花费最少时间it.second/3
//                answer += it.second/3;
//            }else{
//                answer += it.second/3 + 1;
//            }
//        }
        return answer;
    }
};