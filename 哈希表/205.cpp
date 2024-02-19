//
// Created by china on 2024/1/11.
//
#include "string"
#include "map"
#include "vector"
using namespace std;
class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if(s.length()!=t.length()){
            return false;
        }
        map<char,char> cnt_s, cnt_t;
        int n = s.length();
        for (int i = 0; i <n ; ++i) {
            cnt_s[s[i]] = t[i];
            cnt_t[t[i]] = s[i];
        }
        for(int i=0;i<n;i++){
            if(cnt_s[s[i]] != t[i] || cnt_t[t[i]] != s[i]){
                return false;
            }
        }
        return true;
    }
};