//
// Created by china on 2023/12/14.
//
#include "iostream"
#include "map"
#include "algorithm"
using namespace std;
class Solution {
public:
    int romanToInt(string s) {
        int answer = 0, n = s.length();
        map<char, int> own_map = {
                {'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, {'C', 100},{'D', 500}, {'M',1000}
        };
        int pre = own_map[s[0]];
        for(int i=1;i<n;i++){
            int cur = own_map[s[i]];
            if(pre<cur){
                answer-=pre;
            } else{
                answer+=pre;
            }
            pre = cur;
        }
        answer += pre;
        return answer;
    }
};