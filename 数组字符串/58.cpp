//
// Created by china on 2023/12/16.
//
#include "iostream"
using namespace std;
class Solution {
public:
    int lengthOfLastWord(string s) {
        s.erase(s.find_last_not_of(' ') + 1);
        int i = s.length(), ans = 0;
        i--;
        for(i; i>=0;i--){
            if(s[i]!=' '){
                ans++;
            } else{
                break;
            }
        }
        return ans;
    }
};