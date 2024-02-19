//
// Created by china on 2024/1/12.
//
#include "iostream"
#include "map"
#include "string"
using namespace std;
class Solution {
public:
    bool isAnagram(string s, string t) {
        map<char, int> s_c, t_c;
        if(s.length()!=t.length()){
            return false;
        }
        for(int i=0;i<s.length();i++){
            s_c[s[i]]++;
            t_c[t[i]]++;
        }
        for(auto it = s_c.begin();it!=s_c.end();it++){
            if(it->second != t_c[it->first]){
                return false;
            }
        }
        return true;
    }
};