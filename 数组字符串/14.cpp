//
// Created by china on 2023/12/16.
//
#include "algorithm"
#include "string"
#include "vector"
using namespace std;
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.size()==1){
            return strs[0];
        }
        sort(strs.begin(), strs.end());
        string ans = "", str1=strs.front(), str2 = strs.back();
        int n = min(str1.length(), str2.length());
        for(int i=0;i<n;i++){
            if(str1[i]==str2[i]){
                ans += str1[i];
                continue;
            }
            break;
        }
        return ans;
    }
};