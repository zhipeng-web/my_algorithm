//
// Created by china on 2024/5/27.
//
#include <string>
#include "vector"

using namespace std;

class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        vector<int> answer;
        int sum = 0;
        for(int num:rolls){
            sum += num;
        }
        int sub =  (n + rolls.size()) * mean - sum; //剩下n个数的和
        if(sub>6*n || sub<n){ //如果满足不了条件，返回null
            return {};
        }
        int zhengShu = sub/n;
        int yuShu = sub%n;
        for(int i=0;i<yuShu;i++){
            answer.push_back(zhengShu+1);
        }
        for(int i=yuShu;i<n;i++){
            answer.push_back(zhengShu);
        }
        return answer;
    }
};