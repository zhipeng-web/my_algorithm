//
// Created by china on 2024/1/2.
//
#include "iostream"
#include "vector"
#include "string"
#include "unordered_map"
using namespace std;
class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> s_map, t_map;
        int n=s.length(), m=t.length();
        string ans = s;
        int correct = 0;//记录有效字符数
        if(n<m){
            return "";
        }
        for(auto it:t){
            t_map[it]++;
        }
        for(int left=0,right=0;right<n;right++){
            char c = s[right];
            s_map[c]++;
            if(t_map[c]>=s_map[c]){
                correct++;
            }
            while (left<right && s_map[s[left]]>t_map[s[left]]){
                s_map[s[left]]--;
                left++;
            }
            if(correct == m && (right - left + 1) < ans.size()){
                ans = s.substr(left, right - left + 1 );
            }
        }
        return ans;
    }
};