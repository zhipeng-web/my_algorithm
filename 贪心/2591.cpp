//
// Created by china on 2024/4/13.
//
#include "algorithm"
#include "iostream"
using namespace std;
class Solution {
public:
    int distMoney(int money, int children) {
        if(money<children){
            return -1;
        }
        if(money<children+7){
            return 0;
        }
        if(money/children == 8 && money%children ==0){
            return children;
        }
        money -= children;//先每人分一块钱
        int answer =0;
        while (money-7>=0){
            money-=7;
            answer++;
        }
        if(answer>=children){
            return children-1;
        } else{
            if(money==3 && children-answer==1){ //剩余的糖果导致1人分到3个糖
                return answer-1;
            } else{
                return answer;
            }
        }
    }
};

int main(){
    Solution solution;
    cout<<solution.distMoney(17,2);
    return 0;
}